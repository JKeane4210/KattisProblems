//
// Created by Jonny Keane on 7/12/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

class MinSparseTable {
private:
    int* data;
    int size;
public:
    MinSparseTable(int size) : size(size) {
        data = (int *)malloc(size * ((int)floor(log2(size)) + 1) * sizeof(int));
        memset(data, 0, size * ((int)floor(log2(size)) + 1) * sizeof(int));
    }

    int& operator[] (int index) {
        return data[index];
    }

    void populate() {
        int delta = 1;
        for (int level = 1; level <= (int)floor(log2(size)); ++level) {
            for (int i = 0; i < size - delta; ++i) {
                data[size * level + i] = min(data[size * (level - 1) + i], data[size * (level - 1) + i + delta]);
            }
            delta <<= 1;
        }
    }

    int minRange(int start, int end) {
        if (start > end) return minRange(end, start);
        int level = (int)floor(log2(end - start + 1));
        int pow = 1 << level;
        return min(data[level * size + start], data[level * size + end - pow + 1]);
    }

    string toString() {
        string res;
        for (int i = 0; i < (int)floor(log2(size)) + 1; ++i) {
            for (int j = 0; j < size; ++j) {
                res += to_string(data[i * size + j]) + " ";
            }
            res += "\n";
        }
        return res;
    }
};

int* locs;
map<int, vector<int>> conns;
int currInd = 0;

void dfs(int level, int curr, int prev, MinSparseTable table) {
    locs[curr] = ::currInd;
    table[::currInd++] = level;
    for (int conn: conns[curr]) {
        if (conn != prev) {
            dfs(level + 1, conn, curr, table);
            table[::currInd++] = level;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    int V_k[m + 1];
    for (int i = 1; i <= m; ++i) {
        cin >> V_k[i];
    }
    int W_k[n];
    for (int i = 0; i < n; ++i) {
        cin >> W_k[i];
    }
    MinSparseTable table(2 * n - 1);
    locs = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        if (conns.find(a) == conns.end()) {
            conns[a] = vector<int>();
        }
        conns[a].push_back(b);
        if (conns.find(b) == conns.end()) {
            conns[b] = vector<int>();
        }
        conns[b].push_back(a);
    }
    dfs(1, 1, 1, table);
    // sparse table for dfs -> least common ancestor
    table.populate();
    int C_k[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> C_k[i];
    }

    for (int i = 0; i < q; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            C_k[x] = y;
        } else {
            int tbl_A = locs[x];
            int tbl_B = locs[y];
            int depthA = table[tbl_A];
            int depthB = table[tbl_B];
            int least_common_depth = table.minRange(tbl_A, tbl_B);
            int currDepth = depthA;
            int currCity = x;
            long res = 0;
            int counts[m + 1];
            for (int j = 0; j < m + 1; ++j) {
                counts[j] = 0;
            }
            if (x == y) {
                cout << W_k[0] * V_k[C_k[x]] << endl;
                continue;
            }
            bool done = false;
            while (!done) {
//                cout << currCity << " ";
                res += (long)(W_k[counts[C_k[currCity]]]) * (long)(V_k[C_k[currCity]]);
                ++counts[C_k[currCity]];
                done = false;
                bool foundMatch = false;
                for (int conn: conns[currCity]) {
                    if (table[conn] < currDepth) {
                        currDepth = table[conn];
                        currCity = conn;
                        foundMatch= true;
                        break;
                    }
                }
                if (currDepth == least_common_depth - 1 || !foundMatch) {
                    done = true;
                }
            }
            currDepth = depthB;
            currCity = y;
            done = false;
            while (!done) {
//                cout << currCity << " ";
                res += (long)W_k[counts[C_k[currCity]]] * (long)V_k[C_k[currCity]];
                ++counts[C_k[currCity]];
                bool foundMatch = false;
                for (auto conn: conns[currCity]) {
                    if (table[conn] < currDepth) {
                        currDepth = table[conn];
                        currCity = conn;
                        foundMatch = true;
                        break;
                    }
                }
                if (currDepth == least_common_depth || !foundMatch) {
                    done = true;
                }
            }
//            cout << endl;
            cout << res << endl;
        }
    }

    return 0;
}


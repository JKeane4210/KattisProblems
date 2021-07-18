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

    int n;
    cin >> n;
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
//    cout << table.toString() << endl;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + i; j <= n; j += i) {
            int depthA = table[locs[i]];
            int depthB = table[locs[j]];
            int depthC = table.minRange(locs[i], locs[j]);
            res += depthA + depthB - 2 * depthC + 1;
        }
    }
    cout << res << endl;

    return 0;
}
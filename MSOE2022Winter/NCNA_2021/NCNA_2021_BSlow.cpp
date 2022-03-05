//
// Created by Jonny Keane on 3/2/22.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

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

int max_depth = 0;
int* locs;
V<vi> conns;
vi parents;
vi depths;
V<long> digits;
int currInd = 0;

void dfs(int level, int curr, int prev, MinSparseTable table) {
    locs[curr] = ::currInd;
    table[::currInd++] = level;
    parents[curr] = prev;
    depths[curr] = level; // technically unnecessary but convenient
    max_depth = max(level, max_depth);
    for (int conn: conns[curr]) {
        if (conn != prev) {
            dfs(level + 1, conn, curr, table);
            table[::currInd++] = level;
        }
    }
}

int highestOneBit(int i) {
    i |= (i >>  1);
    i |= (i >>  2);
    i |= (i >>  4);
    i |= (i >>  8);
    i |= (i >> 16);
    return i - (((unsigned int)i) >> 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, m, q;
    cin >> n >> m >> q;
    conns = V<vi>(n + 1, vi());
    parents = vi(n + 1);
    depths = vi(n + 1);
    digits = V<long>(n + 1);
    MinSparseTable table((int)(2 * n - 1));
    locs = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        conns[a].push_back(b);
        conns[b].push_back(a);
    }
    dfs(1, 1, -1, table);
    // sparse table for dfs -> least common ancestor
    table.populate();
    for (int i = 1; i <= n; ++i) {
        cin >> digits[i];
    }
    int max_pow = 0;
    long curr_size = 1;
    while (curr_size <= n) {
        curr_size <<= 1;
        ++max_pow;
    }
    unordered_map<int, int> base_2;
    long forward[n + 1][max_pow];
    int k_parent[n + 1][max_pow];
    long backward[n + 1][max_pow];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < max_pow; ++j) {
            if (i == 1) base_2[1 << j] = j;
            forward[i][j] = 0;
            backward[i][j] = 0;
            k_parent[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        long curr_ten = 1 % m;
        long backwards = 0;
        long forwards = 0;
        int curr = i;
        bool done = false;
        for (int j = 0; j < max_pow; ++j) {
            for (int k = (j == 0 ? 0 : 1 << (j - 1)); k < (1 << j); ++k) {
                if (curr == -1) {
                    done = true;
                    break;
                }
                long bw_add = (curr_ten * digits[curr]) % m;
                backwards = (backwards + bw_add) % m;
                forwards = (forwards * 10 + digits[curr]) % m;
                // post
                curr = parents[curr];
                curr_ten = (curr_ten * 10) % m;
            }
            if (done) break;
            forward[i][j] = forwards;
            k_parent[i][j] = curr;
            backward[i][j] = backwards;
        }
    }

    long base_ten_mod[n + 1];
    base_ten_mod[0] = 1l % m;
    for (int i = 1; i <= n; ++i) {
        base_ten_mod[i] = (base_ten_mod[i - 1] * 10l) % m;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < max_pow; ++j) {
            cout << forward[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < max_pow; ++j) {
            cout << backward[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < max_pow; ++j) {
            cout << k_parent[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int query = 0; query < q; ++query) {
        int a, b;
        cin >> a >> b;

        int lca_depth = table.minRange(locs[a], locs[b]);
        unsigned int fw_dist = depths[a] - lca_depth + 1;
        unsigned int bw_dist = depths[b] - lca_depth;
        int fw_start = highestOneBit((int)fw_dist);
        int bw_start = highestOneBit((int)bw_dist);
        long res = 0;
        for (unsigned int i = fw_start; i > 0; i >>= 1) {
            if (fw_dist < i) continue;
            int jump_pow = base_2[i];
            res = (res * base_ten_mod[i]) % m;
            res = (res + forward[a][jump_pow]) % m;
            a = k_parent[a][jump_pow];
            fw_dist -= i;
        }
        long bw_total = 0;
        unsigned int curr_shift = 0;
        for (unsigned int i = bw_start; i > 0; i >>= 1) {
            if ((bw_dist & i) == 0) continue;
            int jump_pow = base_2[i];
            long segment = (backward[b][jump_pow] * base_ten_mod[curr_shift]) % m;
            bw_total = (bw_total + segment) % m;
//            cout << b << " " <<  k_parent[b][jump_pow] << endl;
            b = k_parent[b][jump_pow];
            curr_shift += i;
        }
        res = (res * base_ten_mod[bw_dist]) % m;
        res  = (res + bw_total) % m;
//        cout << bw_total << endl;
        cout << res << endl;
    }
}





/*
5 100000 100
1 2
2 3
3 4
4 5
1 2 3 4 5
1 5
5 1
 */
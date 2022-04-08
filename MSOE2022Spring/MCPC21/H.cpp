#include <bits//stdc++.h>

using namespace std;

class MinSparseTable {
private:
    int * data;
    int size;
public:
    MinSparseTable(int size) : size(size) {
        data = (int * ) malloc(size * ((int)floor(log2(size)) + 2) * sizeof(int));
        memset(data, 0, size * ((int)floor(log2(size)) + 2) * sizeof(int));
    }

    int & operator[] (int index) {
        return data[index];
    }

    void populate() {
        int delta = 1;
        for (int level = 1; level <= (int)floor(log2(size)); ++level) {
            for (int i = 0; i< size - delta; ++i) {
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
};

int* locs;
int* depths;
map<int, vector<int>> conns;
int currInd = 0;
void dfs(int level, int curr, int prev, MinSparseTable table) {
    locs[curr] = ::currInd;
    depths[curr] = level;
    table[::currInd++] = level;
    for(int conn: conns[curr]) {
        if (conn != prev) {
            dfs(level + 1, conn, curr, table);
            table[::currInd++] = level;
        }
    }
}

void solve() {
    ::currInd = 0;
    conns.clear();
    int n;
    cin >> n;
    MinSparseTable table(2 * n - 1);
    locs = (int *) malloc((n + 1) * sizeof(int));
    depths = (int *) malloc((n + 1) * sizeof(int));

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
    table.populate();
    int prev;
    int curr;
    cin >> prev;
    int max_diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        cin >> curr;
        int lca_depth = table.minRange(locs[prev], locs[curr]);
//        cout << depths[curr] + depths[prev] - 2 * lca_depth << endl;
        max_diff = max(max_diff, depths[curr] + depths[prev] - 2 * lca_depth);
        prev = curr;
    }
    cout << (max_diff <= 3) << endl;
//    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

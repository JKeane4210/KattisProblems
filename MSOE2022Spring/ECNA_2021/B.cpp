#include <bits/stdc++.h>

using namespace std;

class MinSparseTable {
public:
    pair<int, int>* data;
    int size;
    MinSparseTable(int size) : size(size) {
        data = (pair<int, int>*) malloc(size * ((int)floor(log2(size) + 1)) * sizeof(pair<int, int>));
        memset(data, 0, size * ((int)floor(log2(size) + 1)) * sizeof(pair<int, int>));
    }

    pair<int, int> & operator[] (int index) {
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

    pair<int, int> minRange(int start, int end) {
        if (start > end) return minRange(end, start);
        int level = (int)floor(log2(end - start + 1));
        int pow = 1 << level;
        return min(data[level * size + start], data[level * size + end - pow + 1]);
    }
};

int * locs;
int * depths;
int * pageCounts;
int * sumPageCounts;
map<int, vector<int>> conns;
int currInd = 0;

void dfs(int level, int curr, int prev, MinSparseTable table) {
    locs[curr] = ::currInd;
    sumPageCounts[curr] = sumPageCounts[prev] + pageCounts[curr];
    depths[curr] = level;
    table[::currInd++] = make_pair(level, curr);
    for (int conn: conns[curr]) {
//        cout << conn << endl;
        dfs(level + 1, conn, curr, table);
        table[::currInd++] = make_pair(level, curr);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    pageCounts = new int[n + 1];
    sumPageCounts = new int[n +1];
    locs = new int[n + 1];
    depths = new int[n + 1];
    int parentCounts[n + 1];
    MinSparseTable table(2 * n - 1);
    for (int i = 1; i <= n; ++i) {
        parentCounts[i] = 0;
        sumPageCounts[i] = 0;
        cin >> pageCounts[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (conns.find(a) == conns.end()) {
            conns[a] = vector<int>();
        }
        ++parentCounts[b];
        conns[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (parentCounts[i] == 0) {
            if (conns.find(0) == conns.end()) {
                conns[0] = vector<int>();
            }
            conns[0].push_back(i);
        }
    }
    dfs(1, 0, 0, table);
    table.populate();
    int res = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            auto lca = table.minRange(locs[i], locs[j]);
//            cout << i << " " <<  j << " " << lca.second << endl;
            if (conns[i].size() == 0 && conns[j].size() == 0 && i != j) {
                res = min(res, sumPageCounts[i] + sumPageCounts[j] - sumPageCounts[lca.second]);
            }
        }
    }
    cout << res << endl;

    return 0;
}
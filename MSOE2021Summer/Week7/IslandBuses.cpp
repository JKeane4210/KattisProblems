//
// Created by Jonny Keane on 7/4/21.
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

int deltas[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> currMap;
    vector<vector<int>> islands;
    vector<vector<int>> bridges;
    vector<vector<int>> buses;
    string line;
    int rows = 0;
    int mapNum = 1;
    int columns = 0;

    while (getline(cin, line)) {
        if (line.empty()) {
            rows = currMap.size();
            // init
            int bridgeNum = 0;
            int islandNum = 0;
            int busNum = 0;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    islands[i][j] = currMap[i][j] == 'X' || currMap[i][j] == '#' ? 0 : -1;
                    bridges[i][j] = currMap[i][j] == 'B' ? 0 : -1;
                    buses[i][j] = islands[i][j] == 0 || bridges[i][j] == 0 ? 0 : -1;
                }
            }
            // islands
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    if (islands[i][j] == 0) {
                        ++islandNum;
                        queue<pair<int, int>> open;
                        open.push(make_pair(i, j));
                        while (!open.empty()) {
                            auto top = open.front();
                            open.pop();
                            if (islands[top.first][top.second] != 0) continue;
                            islands[top.first][top.second] = islandNum;
                            for (auto & delta: deltas) {
                                int r = top.first + delta[0];
                                int c = top.second + delta[1];
                                if (r >= 0 && c >= 0 && r < rows && c < columns) {
                                    open.push(make_pair(r, c));
                                }
                            }
                        }
                    }
                }
            }
            vector<int> connections[islandNum + 1];
            for (int i = 1; i <= islandNum; ++i) {
                connections[i] = vector<int>();
            }
            // bridges
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    if (bridges[i][j] == 0) {
                        ++bridgeNum;
                        int delta[2];
                        int a;
                        if (i > 0 && currMap[i - 1][j] == 'X') {
                            delta[0] = 1;
                            delta[1] = 0;
                            a = islands[i - 1][j];
                        } else {
                            delta[0] = 0;
                            delta[1] = 1;
                            a = islands[i][j - 1];
                        }
                        int r = i;
                        int c = j;
                        while (currMap[r][c] != 'X') {
                            bridges[r][c] = bridgeNum;
                            r += delta[0];
                            c += delta[1];
                        }
                        int b = islands[r][c];
                        connections[a].emplace_back(b);
                        connections[b].emplace_back(a);
                    }
                }
            }
            set<int> visited;
            int curr = 0;
            while (visited.size() != islandNum) {
                ++curr;
                if (visited.count(curr) != 0) continue;
                ++busNum;
                queue<int> q;
                q.push(curr);
                while (!q.empty()) {
                    int top = q.front();
                    q.pop();
                    if (visited.count(top) != 0) continue;
                    visited.insert(top);
                    for (int conn: connections[top]) {
                        q.push(conn);
                    }
                }
            }
            // OUTPUT
            printf("Map %i\n"
                   "islands: %i\n"
                   "bridges: %i\n"
                   "buses needed: %i\n\n", mapNum, islandNum, bridgeNum, busNum);
            currMap.clear();
            islands.clear();
            bridges.clear();
            buses.clear();
            ++mapNum;
        } else {
            columns = line.size();
            currMap.emplace_back(line);
            islands.emplace_back(vector<int>(line.size()));
            bridges.emplace_back(vector<int>(line.size()));
            buses.emplace_back(vector<int>(line.size()));
        }
    }

    rows = currMap.size();
    // init
    int bridgeNum = 0;
    int islandNum = 0;
    int busNum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            islands[i][j] = currMap[i][j] == 'X' || currMap[i][j] == '#' ? 0 : -1;
            bridges[i][j] = currMap[i][j] == 'B' ? 0 : -1;
            buses[i][j] = islands[i][j] == 0 || bridges[i][j] == 0 ? 0 : -1;
        }
    }
    // islands
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (islands[i][j] == 0) {
                ++islandNum;
                queue<pair<int, int>> open;
                open.push(make_pair(i, j));
                while (!open.empty()) {
                    auto top = open.front();
                    open.pop();
                    if (islands[top.first][top.second] != 0) continue;
                    islands[top.first][top.second] = islandNum;
                    for (auto & delta: deltas) {
                        int r = top.first + delta[0];
                        int c = top.second + delta[1];
                        if (r >= 0 && c >= 0 && r < rows && c < columns) {
                            open.push(make_pair(r, c));
                        }
                    }
                }
            }
        }
    }
    vector<int> connections[islandNum + 1];
    for (int i = 1; i <= islandNum; ++i) {
        connections[i] = vector<int>();
    }
    // bridges
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (bridges[i][j] == 0) {
                ++bridgeNum;
                int delta[2];
                int a;
                if (i > 0 && currMap[i - 1][j] == 'X') {
                    delta[0] = 1;
                    delta[1] = 0;
                    a = islands[i - 1][j];
                } else {
                    delta[0] = 0;
                    delta[1] = 1;
                    a = islands[i][j - 1];
                }
                int r = i;
                int c = j;
                while (currMap[r][c] != 'X') {
                    bridges[r][c] = bridgeNum;
                    r += delta[0];
                    c += delta[1];
                }
                int b = islands[r][c];
                connections[a].emplace_back(b);
                connections[b].emplace_back(a);
            }
        }
    }
    set<int> visited;
    int curr = 0;
    while (visited.size() != islandNum) {
        ++curr;
        if (visited.count(curr) != 0) continue;
        ++busNum;
        queue<int> q;
        q.push(curr);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            if (visited.count(top) != 0) continue;
            visited.insert(top);
            for (int conn: connections[top]) {
                q.push(conn);
            }
        }
    }
    // OUTPUT
    printf("Map %i\n"
           "islands: %i\n"
           "bridges: %i\n"
           "buses needed: %i\n\n", mapNum, islandNum, bridgeNum, busNum);
    // how do I read for EOF better in C++?

    return 0;
}
//
// Created by keanej on 10/1/2022.
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
#define wgraph V<V<pii>>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int DIRS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int grid[n][m];
    int shortest[n][m];
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < m; ++j) {
            grid[i][j] = line[j] - '0';
            shortest[i][j] = INT_MAX;
        }
    }
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push(mp(0, mp(0, 0)));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (shortest[top.second.first][top.second.second] <= top.first) continue;
        shortest[top.second.first][top.second.second] = top.first;
        for (auto dir: DIRS) {
            int nx = top.second.second + dir[0] * grid[top.second.first][top.second.second];
            int ny = top.second.first + dir[1] * grid[top.second.first][top.second.second];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (shortest[ny][nx] <= top.first + 1) continue;
                pq.push(mp(top.first + 1, mp(ny, nx)));
            }
        }
    }
    if (shortest[n - 1][m - 1] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << shortest[n - 1][m - 1] << endl;
    }

    return 0;
}
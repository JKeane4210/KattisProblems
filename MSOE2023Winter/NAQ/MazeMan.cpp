//
// Created by keanej on 2/22/2023.
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

int deltas[4][2] = {{1, 0}, {0 ,1}, {-1, 0}, {0, -1}};

string grid[100];

int fill(int i, int j, int n, int m) {
    queue<pii> q;
    q.push({i, j});
    int res = 0;
    bool first = true;
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        i = top.first, j = top.second;
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 'X') continue;
        if (!first && (grid[i][j] >= 'A' && grid[i][j] <= 'W')) continue;
        first = false;
        res += grid[i][j] == '.';
        grid[i][j] = 'X';
        for (auto delta: deltas) {
            q.push({i + delta[0], j + delta[1]});
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int dots = 0;

    getline(cin, grid[0]);
    for (int i = 0; i < n; ++i) {
        getline(cin, grid[i]);
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.') dots++;
        }
    }

    int count = 0;

    for (int i = 1; i < n - 1; ++i) {
        if (grid[i][0] >= 'A' && grid[i][0] <= 'W') {
            int d = fill(i, 0, n, m);
            count += d > 0;
            dots -= d;
        }
        if (grid[i][m - 1] >= 'A' && grid[i][m - 1] <= 'W') {
            int d = fill(i, m - 1, n, m);
            count += d > 0;
            dots -= d;
        }
    }

    for (int i = 1; i < m - 1; ++i) {
        if (grid[0][i] >= 'A' && grid[0][i] <= 'W') {
            int d = fill(0, i, n, m);
            count += d > 0;
            dots -= d;
        }
        if (grid[n - 1][i] >= 'A' && grid[n - 1][i] <= 'W') {
            int d = fill(n  - 1, i, n, m);
            count += d > 0;
            dots -= d;
        }
    }

    cout << count << " " << dots << endl;

    return 0;
}
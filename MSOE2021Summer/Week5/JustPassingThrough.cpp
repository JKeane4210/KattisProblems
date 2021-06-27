//
// Created by Jonny Keane on 6/26/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, n;
    cin >> r >> c >> n;
    pair<int, bool> grid[r][c];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int h;
            cin >> h;
            grid[i][j] = make_pair(h, false);
        }
    }
    for (int i = 1; i < r - 1; ++i) {
        for (int j = 1; j < c - 1; ++j) {
            if (grid[i - 1][j].first != -1 && grid[i + 1][j].first != -1 && grid[i][j - 1].first != -1 && grid[i][j + 1].first != -1 &&
                grid[i + 1][j] > grid[i][j] && grid[i - 1][j] > grid[i][j] && grid[i][j - 1] < grid[i][j] && grid[i][j + 1] < grid[i][j]) {
                grid[i][j].second = true;
            }
        }
    }
    int dp[r][c][n + 1];
    for (int i = 0; i < r; ++i) {
        dp[i][0][0] = grid[i][0].first != -1 ? grid[i][0].first : INT_MAX;
        for (int j = 1; j < n + 1; ++j) {
            dp[i][0][j] = INT_MAX;
        }
        for (int j = 1; j < c; ++j) {
            for (int k = 0; k < n + 1; ++k) {
                dp[i][j][k] = INT_MAX;
            }
        }
    }

    for (int j = 0; j < c - 1; ++j) {                                                                                               // column
        for (int i = 0; i < r; ++i) {                                                                                               // row
            if (grid[i][j].first != -1) {                                                                                           // valid
                for (int k = -1; k <= 1; ++k) {                                                                                     // delta
                    if (i + k >= 0 && i + k < r && grid[i + k][j + 1].first != -1) {                                                // delta valid
                        if (grid[i + k][j + 1].second) {                                                                            // new pass
                            for (int l = 0; l < n; ++l) {                                                                           // update one up (looking for exactly)
                                if (dp[i][j][l] != INT_MAX) {
                                    dp[i + k][j + 1][l + 1] = min(dp[i + k][j + 1][l + 1],
                                                                  dp[i][j][l] + grid[i + k][j + 1].first);
                                }
                            }
                        } else {                                                                                                    // no new pass
                            for (int l = 0; l < n + 1; ++l) {                                                                       // update same level
                                if (dp[i][j][l] != INT_MAX) {
                                    dp[i + k][j + 1][l] = min(dp[i + k][j + 1][l], dp[i][j][l] + grid[i + k][j + 1].first);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int min_ = INT_MAX;
    for (int i = 0; i < r; ++i) {
        if (grid[i][c - 1].first != -1) {
            min_ = min(dp[i][c - 1][n], min_);
        }
    }
    if (min_ == INT_MAX) {
        cout << "impossible" << endl;
    } else {
        cout << min_ << endl;
    }

    return 0;
}
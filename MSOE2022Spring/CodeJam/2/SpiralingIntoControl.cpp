//
// Created by Jonny Keane on 5/14/22.
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

// Lessons from Today's round:
// - Learn how to step back when things are going wrong
//  - Hopefully this is not related with my set up, but unpredictable things happen and I have to react
// - If you can solve problems for points, do it. Would have qualified if I had just brute forced easy cases
//      on both problems and then seen what I could have scraped together to get myself to qualification

int DELTAS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve(int case_num) {
    int n, k;
    cin >> n >> k;
    int arr[n][n];
    int r = 0, c= 0;
    int dir = 0;
    int curr_row = 0;
    int curr_col = 0;
    int l = n;
    int gr = n / 2, gc = n / 2;
    int sr = -1, sc = -1;
    int curr_dist = -1;
    for (int i = 1; i <= n * n; ++i) {
        arr[r][c] = i;
        // cout << r << " " << c << " " << i << endl;
        if (i - 1 + abs(gr - r) + abs(gc - c) == k) {
            sr = r, sc = c;
            curr_dist = abs(gr - r) + abs(gc - c);
        }
        if (dir == 0) {
            ++c;
            ++curr_col;
        } else if (dir == 1) {
            ++r;
            ++curr_row;
        } else if (dir == 2) {
            --c;
            ++curr_col;
        } else if (dir == 3) {
            --r;
            ++curr_row;
        }
        if (dir == 0 && curr_col == l - 1) {
            dir = 1;
            curr_row = 0;
            curr_col = 0;
        } else if (dir == 1 && curr_row == l - 1) {
            dir = 2;
            curr_row = 0;
            curr_col = 0;
        } else if (dir == 2 && curr_col == l - 1) {
            dir = 3;
            curr_row = 0;
            curr_col = 0;

        } else if (dir == 3 && curr_row == l - 1) {
            dir = 0;
            l -= 2;
            curr_row = 0;
            curr_col = 0;
            ++c; ++r;
        }
    }
    // for (int i = 0; i < n; ++i) {
    // 	for (int j = 0; j < n; ++j) {
    // 		cout << arr[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    if (sr == -1) {
        cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
    } else {
        r = sr, c = sc;
        // cout << sr << " " << sc << " *" << endl;
        vector<pair<int, int>> shorts;
        while (r != gr || c != gc) {
            for (auto delta: DELTAS) {
                int nr = r + delta[0];
                int nc = c + delta[1];
                if (nr < n && nr >= 0 && nc < n && nc >= 0 && abs(nr - gr) + abs(nc - gc) < curr_dist && arr[nr][nc] - arr[r][c] > 0) {
                    curr_dist = abs(nr - gr) + abs(nc - gc);
                    if (arr[nr][nc] - arr[r][c] > 1) {
                        shorts.push_back(make_pair(arr[r][c], arr[nr][nc]));
                    }
                    // cout << r << " " << c << " -> " << nr << " " << nc << endl;
                    r = nr;
                    c = nc;

                    break;
                }
            }
        }
        cout << "Case #" << case_num << ": " << shorts.size() << endl;
        for (auto p: shorts) {
            cout << p.first << " " << p.second << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }

    return 0;
}
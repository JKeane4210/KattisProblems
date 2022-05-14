//
// Created by Jonny Keane on 5/14/22.
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

// use M_PI for PI

using namespace std;

void solve(int case_num) {
    int r;
    cin >> r;
    int grid[2 * r + 1][2 * r + 1];
    int wrong[2 * r + 1][2 * r + 1];
    for (int i = 0; i < 2 * r + 1; ++i)
    {
        for (int j = 0; j < 2 * r + 1; ++j) {
            grid[i][j] = 0;
            wrong[i][j] = 0;
        }
    }
    for (int x = -r; x <=r; ++x) {
        for (int y = -r; y <= r; ++y) {
            if (round(sqrt(x * x  + y * y)) <= r)  {
                grid[x + r][y + r] = 1;
            }
        }
    }
    for (int v = 0; v <= r; ++v) {
        for (int x = -v; x <= v; ++x) {
            int y = (int)round(sqrt(v * v - x * x));
//            cout << y << endl;
            wrong[x + r][y + r] = 1;
            wrong[x + r][-y + r] = 1;
            wrong[y + r][x + r] = 1;
            wrong[-y + r][x + r] = 1;
        }
    }
    int tot_right = 0;
    int tot_wrong = 0;
    for (int i = 0; i < 2 * r + 1; ++i)
    {
        for (int j = 0; j < 2 * r + 1; ++j) {
            // cout << grid[i][j];
            tot_right += grid[i][j];
            tot_wrong += wrong[i][j];
        }
        // cout << endl;
    }
    cout << "Case #" << case_num << ": " << tot_right - tot_wrong << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve(i + 1);
    }

    return 0;
}
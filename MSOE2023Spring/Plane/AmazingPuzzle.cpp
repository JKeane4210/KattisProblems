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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c, r, e;
    cin >> c >> r >> e;
    // TODO: convert e to scaled coordinates
    int grid_r = r * 2 + 1;
    int grid_c = c * 2 + 1;
    int grid[grid_r][grid_c];
    for (int i = 0; i < grid_r; ++i) {
        for (int j = 0; j < grid_c; ++j) {
            grid[i][j] = 0;
        }
    }
    cin >> c >> r >> e;
    for (int i = 0; i < 2; ++i) {
        int rc, rr;
        string rd;
        cin >> rc >> rr >> rd;
        rr*=2;
        rc*=2;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ec, er;
        cin >> ec >> er;
        ec = ec * 2 + 1;
        er = er * 2 + 1;
        grid[er][ec] = -1;
    }
    // it's a small grid
    // it's very annoying to code
    // stated dijkstras [row, col, bumps]
    // make sure you are checking that you are not overlapping robots
    
    return 0;
}
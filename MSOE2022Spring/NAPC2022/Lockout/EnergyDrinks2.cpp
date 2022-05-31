//
// Created by keanej on 5/28/2022.
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

int deltas[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    string grid[n];
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;

    int shortest[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            shortest[i][j] = INT_MAX;
        }
    }


    return 0;
}
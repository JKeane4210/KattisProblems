//
// Created by Jonny Keane on 2/9/22.
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

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // really interesting way of thinking about it because of precision
    // turning complex geometry into a more discrete grid
    int n;
    cin >> n;
    bool grid[81][81];
    for (int i = 0; i < 81; ++i) {
        for (int j = 0; j < 81; ++j) {
            grid[i][j] = false;
        }
    }
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        for (int j = -40; j <= 40; ++j) {
            for (int k = -40; k <= 40; ++k) {
                if (dist((double)j / 2, (double)k / 2, (double)x, (double)y) <= (double)r) {
                    grid[j + 40][k + 40] = true;
                }
            }
        }
    }
    double res = 0;
    for (int i = 0; i < 81; ++i) {
        for (int j = 0; j < 81; ++j) {
            if (grid[i][j]) {
                res += 0.25;
            }
        }
    }
    cout << res << endl;

    return 0;
}
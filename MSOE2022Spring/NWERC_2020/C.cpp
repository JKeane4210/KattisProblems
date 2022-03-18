//
// Created by Jonny Keane on 3/14/22.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int total, total_solve, total_diff, solve_diff;
    cin >> total >> total_solve >> total_diff >> solve_diff;

    double res = 1.0 / (total - total_solve) * 1.0 * (total * total_diff - total_solve * solve_diff);
    cout.precision(10);
    if (res <= 100 && res >= 0) {
        cout << res << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
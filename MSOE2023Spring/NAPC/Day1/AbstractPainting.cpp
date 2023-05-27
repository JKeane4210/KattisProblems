//
// Created by keanej on 5/26/2023.
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

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll r, c;
        cin >> r >> c;
        ll ans = 18;
        for (ll i = 1; i < r; ++i) {
            ans = (ans * 6) % MOD; // 3 possibilities for choosing other side, 2 possible colors to choose
        }
        for (ll i = 1; i < c; ++i) {
            ans = (ans * 6) % MOD; // 3 possibilities for choosing other side, 2 possible colors to choose
        }
        for (int i = 1; i < r; ++i) {
            for (int j = 1; j < c; ++j) {
                ans = (ans * 2) % MOD; // in either of cases, 2 possible configurations
            }
        }
        cout << ans << endl;
    }

    return 0;
}
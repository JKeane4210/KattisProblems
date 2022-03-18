//
// Created by Jonny Keane on 3/17/22.
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

long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, a, b, c;
    cin >> n >> a >> b >> c;

    long rides[n][3];
    rides[0][0] = a;
    rides[0][1] = b;
    rides[0][2] = c;
    for (int i = 1; i < n; ++i) {
        rides[i][0] = ((rides[i - 1][1] + rides[i - 1][2]) * a) % MOD;
        rides[i][1] = ((rides[i - 1][0] + rides[i - 1][2]) * b) % MOD;
        rides[i][2] = ((rides[i - 1][0] + rides[i - 1][1]) * c) % MOD;
    }
    long res = (rides[n - 1][0] + rides[n - 1][1] + rides[n - 1][2]) % MOD;
    cout << res << endl;

    return 0;
}
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

    int n;
    cin >> n;
    long tot[n][2];
    for (int i = 0; i < n; ++i) {
        tot[i][0] = 0, tot[i][1] = 0;
    }
    tot[0][0] = 1;
    tot[1][0] = 0;
    tot[0][1] = 0;
    tot[1][1] = 1;
    for (int i = 2; i < n; ++i) {
        tot[i][0] = (tot[i - 2][0] + tot[i - 1][1]) % MOD;
        tot[i][1] = (tot[i - 2][1] + tot[i - 2][0]) % MOD; // number of strings ending in a b + number of strings ending in an a
    }
//    for (int i = 0; i < n; ++i) {
//        cout << tot[i][0] << " " << tot[i][1] << endl;
//    }
    cout << (tot[n - 1][0] + tot[n - 1][1]) % MOD << endl;

    return 0;
}
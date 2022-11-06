//
// Created by keanej on 11/6/2022.
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

ll MOD = 998244353;

using namespace std;

void solve() {
    ll n, m;
    cin >> n >> m;
    ll poss = 1;
    ll prev;
    ll curr;
    cin >> prev;
    curr = prev;
    ll can_choose = m;
    for (int i = 1; i < n; ++i) {
        ll v;
        cin >> v;
        ll g = gcd(curr, v);
        if ((g != v && g != 1) || prev < v) {
            poss = 0;
        } else if (g == 1) { // if they are co-prime
//            cout << "a" << (m - (m / v)) << endl;
            poss = (poss * can_choose) % MOD;
            can_choose -= m - m / v;
//            curr ;
        } else { // if they are a multiple of each other
//            cout << "b" << (m / v) << endl;
            poss = (poss * can_choose) % MOD;
            can_choose -= m / v;
        }
        prev = v;
    }
    cout << poss << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
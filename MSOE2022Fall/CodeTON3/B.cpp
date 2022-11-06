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

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll px = 0;
    ll py = 0;
    ll c1 = 0;
    ll c0 = 0;
    ll plx = 0;
    ll ply = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            c0++;
            plx++;
            px = max(px, plx);
            py = max(py, ply);
            ply = 0;
        } else {
            c1++;
            ply++;
            py = max(py, ply);
            px = max(px, plx);
            plx = 0;
        }
    }

    ll res = max(px * px, py * py);
    if (c0 > 0 && c1 > 0) {
        res = max(res, c0 * c1);
    }
    cout << res << endl;
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
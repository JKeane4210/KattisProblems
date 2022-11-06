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
    string a, b;
    cin >> a >> b;
    int c1 = (a[0] == '1') + (b[0] == '1');
    int c0 = (a[0] == '0') + (b[0] == '0');
//    cout << c1 << " " << c0 << endl;
    for (int i = 1; i < n; ++i) {
        c1 += (a[i] == '1') + (b[i] == '1');
        c0 += (a[i] == '0') + (b[i] == '0');
//        cout << c1 << " " << c0 << endl;
        if (c1 == 3 || c0 == 3) {
            cout << "NO" << endl;
            return;
        }
        c1 -= (a[i - 1] == '1') + (b[i - 1] == '1');
        c0 -= (a[i - 1] == '0') + (b[i - 1] == '0');
    }
    cout << "YES" << endl;
    vpii out;
    if (a != b) {
        out.pb(mp(0, n-1));
        for (int i = 0; i < n; ++i) {
            if (a[i] == '0') {
                a[i] = '1';
            } else {
                a[i] = '0';
            }
        }
    }
        int l = 0, r = -1, i = 0;
        while (i < n) {
            if (a[i] == '1') {
                l = i;
                r = i;
                while (i < n && a[i + 1] == '1') {
                    ++i;
                    r = i;
                }
//                cout << ":" << l << " " << r << endl;
                if (r == n - 1) {
                    if (l != r) {
                        out.pb(mp(l, r-1));
                        out.pb(mp(r, r));
                    }
                    else {
                        out.pb(mp(l-1, r));
                        out.pb(mp(l-1, l-1));
                    }
                } else {
                    out.pb(mp(l, r+1));
                    out.pb(mp(r+1, r+1));
                }
            }
            ++i;
        }
    cout << out.size() << endl;
    for (auto p: out) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
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
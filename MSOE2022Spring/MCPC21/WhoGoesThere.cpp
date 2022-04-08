//
// Created by Jonny Keane on 3/23/22.
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

    int n, m;
    cin >> n >> m;
    int a[m];
    int r[m];
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        r[i] = 0;
    }
    while (n > 0) {
        bool all_pass = true;
        for (int i = 0; i < m; ++i) {
            if (a[i] > 0 && n > 0) {
                all_pass = false;
                --a[i];
                ++r[i];
                --n;
            }
        }
        if (all_pass) break;
    }
    for (int i = 0; i < m; ++i) {
        cout << r[i] << endl;
    }

    return 0;
}
//
// Created by keanej on 11/12/2022.
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
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int count[10];
        for (int j = 0; j < 10; ++j) {
            count[j] = 0;
        }
        int d = 0;
        int mi = s[i] - '0';
        for (int j = i; j < n; ++j) {
            if (j - i + 1 > 100) break;
            int c = s[j] - '0';
            if (count[c] == 0) {
                d++;
            }
            count[c]++;
            if (count[mi] < count[c]) {
//                cout << c << " takeover " << mi << endl;
                mi = c;
            }
//            cout << i << " " << j << " " << d << " " << count[mi] << endl;
            if (count[mi] <= d) {
                res++;
            }
        }
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
//
// Created by Jonny Keane on 3/1/22.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

bool is_even(const string & s) {
//    cout << s << endl;
    int counts[6];
    for (int & count : counts) { count = 0; }
    for (char c: s) {
        counts[c - 'a']++;
    }
    for (int count: counts) {
        if (count % 2 == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int q;
    cin >> q;
    for (int k = 0; k < q; ++k) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r;
            --l; --r;
            int res = 0;
            for (int i = l; i <= r; ++i) {
                for (int len = 1; len <= r - i + 1; ++len) {
                    if (is_even(s.substr(i, len))) {
                        ++res;
                    }
                }
            }
            cout << res << endl;
        } else {
            int i;
            string x;
            cin >> i >> x;
            --i;
            s[i] = x[0];
        }
    }

    return 0;
}
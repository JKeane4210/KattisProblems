//
// Created by Jonny Keane on 3/6/22.
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

void solve() {
    unordered_map<string, int> attrs;
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n; ++i) {
        string category, attr;
        cin >> category >> attr;
        attrs[attr]++;
    }
    int prod = 1;
    for (const auto& p: attrs) {
        prod *= p.second + 1;
    }
    cout << prod - 1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        solve();
    }

    return 0;
}
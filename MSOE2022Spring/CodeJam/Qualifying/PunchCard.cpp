//
// Created by Jonny Keane on 4/2/22.
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

void solve(int num) {
    int r, c;
    cin >> r >> c;
    cout << "Case #" << num + 1 << ":" << endl;
    for (int i = 0; i < 2 * r + 1; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i < 2  && j < 1) {
                cout << "..";
            } else if (i % 2 == 0) {
                cout << "+-";
            } else {
                cout << "|.";
            }
        }
        if (i % 2 == 0) {
            cout << "+" << endl;
        } else {
            cout << "|" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve(i);
    }

    return 0;
}
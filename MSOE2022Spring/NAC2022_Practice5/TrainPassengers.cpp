//
// Created by Jonny Keane on 5/21/22.
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

    int c, n;
    cin >> c >> n;
    int curr_cap = 0;
    for (int i = 0; i < n; ++i) {
        int leave, enter, stay;
        cin >> leave >> enter >> stay;
        if (curr_cap - leave < 0) {
            cout << "impossible" << endl;
            return 0;
        }
        curr_cap -= leave;
        if (curr_cap + enter > c) {
            cout << "impossible" << endl;
            return 0;
        }
        curr_cap += enter;
        if (curr_cap < c && stay != 0) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    if (curr_cap != 0) {
        cout << "impossible" << endl;
        return 0;
    }
    cout << "possible" << endl;

    return 0;
}
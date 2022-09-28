//
// Created by keanej on 9/27/2022.
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

ll n, k, q;

vll getpath(ll x) {
    vll res;
    res.pb(x);
    ll count = 1;
    ll add = k;
    int level = 0;
    while (count < x) {
        count += add;
        add *= k;
        ++level;
    }
    ll curr_row_count = add / k;
    while (level != 0) {
        count -= curr_row_count; // make the count the amount remaining after we get rid of this row
        curr_row_count /= k; // get curr row count ready for next iteration
        --level; // decrease level
        res.pb(count - curr_row_count + ((x - count - 1) / k) + 1);
        x = res[res.size() - 1];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> q;
    while (q != 0) {
        ll x, y;
        cin >> x >> y;
        if (y == 1) swap(x, y);
        if (x == 1) cout << getpath(y).size() - 1 << endl;
        else {
            vll px = getpath(x);
            vll py = getpath(y);
            int x_i = 0;
            int y_i = 0;
            int dist = 0;
            while (px[x_i] != py[y_i]) {
                ++dist;
                if (px[x_i] > py[y_i]) {
                    ++x_i;
                } else {
                    ++y_i;
                }
            }
            cout << dist << endl;
        }
        --q;
    }
    return 0;
}
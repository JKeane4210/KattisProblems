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

    int n;
    cin >> n;
    int towers[n];
    for (int i = 0; i < n; ++i) {
        cin >> towers[i];
    }
    sort(towers, towers + n);
    int res = n;
    int ind = 0;
    while (ind != n) {
        int curr = towers[ind];
//        cout << curr;
        while (ind != n && towers[ind] == curr) {
            ++ind;
        }
//        cout << " " << ind << endl;
        res = min(res, towers[ind - 1] + n - ind);
    }
    cout << res << endl;

    return 0;
}
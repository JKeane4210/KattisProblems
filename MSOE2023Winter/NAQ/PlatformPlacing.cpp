//
// Created by keanej on 2/21/2023.
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

    ll n, s, k;
    cin >> n >> s >> k;
    s *= 2;
    k *= 2;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] *= 2;
    }
    sort(arr, arr + n);
    ll res = 0;
    ll left = arr[0] - (k / 2);
    for (int i = 0; i < n; ++i) {
        ll right = LONG_LONG_MAX;
        if (i != n - 1) right = arr[i + 1] - (s / 2);
        ll space_left = arr[i] - left;
        ll space_right = right - arr[i];
        ll side_space = min(space_left, space_right);
        if (side_space * 2 < s) {
            cout << -1 << endl;
            return 0;
        }
        ll length = min(side_space * 2, k);
        res += length / 2;
        left = arr[i] + length / 2;
    }

    cout << res << endl;

    return 0;
}
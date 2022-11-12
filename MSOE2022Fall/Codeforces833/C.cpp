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

int max_count(ll * arr, int n, int i) {
    if (i == n) return 0;
    map<ll, int> m;
    ll sum = 0;
    ll max_num = arr[i];
    m[max_num] = 1;
    for (int j = i + 1; j < n; ++j) {
        if (arr[j] == 0) {
            return m[max_num] + max_count(arr, n, j);
        }
        sum += arr[j];
        m[sum]++;
//        cout << sum << endl;
        if (m[max_num] < m[sum]) {
            max_num = sum;
        }
    }
    return m[max_num];
}

void solve() {
    int n;
    cin >> n;
    ll arr[n];
    int decision = n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
//        cout << arr[i] << " ";
        if (arr[i] == 0 && decision == n) {
            decision = i;
        }
    }
//    cout << endl;
    int mc = max_count(arr, n, decision);
    int res = 0;
    ll sum = 0;
    for (int i = 0; i < decision; ++i) {
        sum += arr[i];
        if (sum == 0) {
            res++;
        }
    }
    cout << res + mc << endl;
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
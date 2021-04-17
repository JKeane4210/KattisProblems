//
// Created by Jonny Keane on 4/3/21.
//
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        int k;
        int toys[k];
        cin >> k;
        for(int j = 0; j < k; ++j) {
            cin >> toys[k];
        }
    }
    for (int i = 0; i < p; ++i) {
        int l;
        cin >> l;
        int category[l];
        for (int j = 0; j < l; ++j) {
            cin >> category[j];
        }
    }

    return 0;
}

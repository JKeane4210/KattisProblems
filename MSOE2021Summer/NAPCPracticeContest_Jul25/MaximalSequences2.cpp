//
// Created by Jonny Keane on 7/25/21.
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

    int n;
    cin >> n;
    int levels = (int)log2(n);
    unordered_set<int> valsInRanges[levels + 1][n];
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        valsInRanges[0][i] = unordered_set<int>({val});
    }
    int q;
    cin >> q;
    for (int x = 0; x < q; ++x) {
        int i, m;
        cin >> i >> m;
        --i;
        unordered_set<int> valid;
        for (int j = 0; j < m; ++j) {
            int am;
            cin >> am;
            valid.insert(am);
        }
    }
    return 0;
}
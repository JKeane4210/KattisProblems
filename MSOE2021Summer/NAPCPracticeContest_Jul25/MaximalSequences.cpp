//
// Created by Jonny Keane on 7/25/21.
//

#include <bits/stdc++.h>

#include <utility>

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

unordered_set<int> get_union(const unordered_set<int>& a, const unordered_set<int>& b) {
    unordered_set<int> res(a);
    for (int v: b) {
        res.insert(v);
    }
    return res;
}

bool holds(const unordered_set<int> & rangeSet, const unordered_set<int> & valid) {
    for (int v: rangeSet) {
        if (valid.count(v) == 0) {
            return false;
        }
    }
    return true;
}

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
    int delta = 1;
    for (int i = 1; i <= levels; ++i) {
        for (int j = 0; j < n - delta; ++j) {
            valsInRanges[i][j] = get_union(valsInRanges[i - 1][j], valsInRanges[i - 1][j + delta]);
        }
        delta <<= 1;
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
        int res = 0;
        int currLevel = (int)log2(n - i);
        while (currLevel >= 0 && i < n) {
            if (i + (1 << currLevel) - 1 < n && holds(valsInRanges[currLevel][i], valid)) {
                i += 1 << currLevel;
                res += 1 << currLevel;
            }
            --currLevel;
        }
        cout << res << endl;
    }

    return 0;
}
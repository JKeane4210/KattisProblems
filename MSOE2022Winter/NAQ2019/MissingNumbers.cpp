//
// Created by Jonny Keane on 1/18/22.
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
    set<int> vals;
    int max_ = 0;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        vals.insert(val);
        max_ = max(max_, val);
    }
    bool good = true;
    for (int i = 1; i <= max_; ++i) {
        if (vals.find(i) == vals.end()) {
            cout << i << endl;
            good = false;
        }
    }
    if (good) {
        cout << "good job" << endl;
    }

    return 0;
}
//
// Created by Jonny Keane on 7/17/21.
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

pair<pair<int, int>, bool> abilities(const string& s, int n) {
    int reds = 0;
    int blues = 0;
    bool canShift = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] != s[(i + 1) % n]) {
            if (s[i] == 'R') {
                ++reds;
            } else {
                ++blues;
            }
        } else {
            canShift = true;
        }
    }
    if (reds == 0 && blues == 0) {
        if (s[0] == 'R') {
            reds = 1;
        } else {
            blues = 1;
        }
    }
    return make_pair(make_pair(reds, blues), canShift);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string src, res;
    cin >> src >> res;
    auto abSrc = abilities(src, n);
    auto abRes = abilities(res, n);
    bool enoughReds = abSrc.first.first >= abRes.first.first;
    bool enoughBlues = abSrc.first.second >= abRes.first.second;
    bool shiftlessEnough = abSrc.first.first > 0 && abSrc.first.second > 0 &&
            abSrc.first.first - 1 >= abRes.first.first && abSrc.first.second - 1 >= abRes.first.second;
    bool canShift = abSrc.second;
    if ((canShift && enoughBlues && enoughReds) || shiftlessEnough) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
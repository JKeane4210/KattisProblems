//
// Created by Jonny Keane on 1/29/22.
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

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    for (int p1 = 0; p1 < points.size() - 1; ++p1) {
        bool found = false;
        for (int p2 = p1 + 1; p2 < points.size() - 1; ++p2) {
            double l1_norm = 1.0 * (points[p1 + 1].second - points[p1].second) / (points[p1 + 1].first - points[p1].first);
            double y_min = points[p1].second + l1_norm * (points[p2 + 1].first - points[p1].first);
            if (y_min < points[p2 + 1].second) { // CASE
                cout << p2 + 1 << " ";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "0 ";
        }
    }
    cout << endl;
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
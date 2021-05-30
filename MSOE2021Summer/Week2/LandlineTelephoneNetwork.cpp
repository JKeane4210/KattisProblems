//
// Created by Jonny Keane on 5/30/21.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;
    set<pair<int, int>> incoming[n];

    unordered_set<int> insecure;
    for (int i = 0; i < p; ++i) {
        int b;
        cin >> b;
        insecure.insert(b);
    }

    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        if (insecure.count(a) == 0 && insecure.count(b) == 0) {
            incoming[a - 1].insert(make_pair(w, b - 1));
            incoming[b - 1].insert(make_pair(w, a - 1));
        } else if (insecure.count(a) == 0 && insecure.count(b) != 0) {
            incoming[b - 1].insert(make_pair(w, a - 1));
        } else if (insecure.count(b) == 0 && insecure.count(a) != 0) {
            incoming[a - 1].insert(make_pair(w, b - 1));
        }
    }

    int totalWeight = 0;
    bool removalMade = false;
    for (int i = 0; i < n; ++i) {
        auto weights = incoming[i];
        if (!weights.empty()) {
            if (!removalMade || (*incoming[(*weights.begin()).second].begin()).second != i) {
                totalWeight += (*weights.begin()).first;
                if ((*incoming[(*weights.begin()).second].begin()).second == i) {
                    removalMade = true;
                }
            }
        } else {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << totalWeight << endl;
    return 0;
}


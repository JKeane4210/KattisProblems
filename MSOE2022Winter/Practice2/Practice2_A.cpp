//
// Created by Jonny Keane on 2/5/22.
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
    map<int, int> last_seen;
    int order[n];
    for (int i = 0; i < n; ++i) {
        cin >> order[i];
    }

    int min_dist = n;
    for (int i = 0; i < n; ++i) {
        if (last_seen.find(order[i]) != last_seen.end()) {
            min_dist = min(min_dist, i - last_seen[order[i]]);
        }
        last_seen[order[i]] = i;
    }
    cout << min_dist << endl;

    return 0;
}
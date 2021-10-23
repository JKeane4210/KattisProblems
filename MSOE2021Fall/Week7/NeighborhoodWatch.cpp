//
// Created by Jonny Keane on 10/21/21.
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

    int n, m;
    cin >> n >> m;
    int safes[n];
    for (int i = 0; i < m; ++i) {
        cin >> safes[i];
    }
    long res = 0;
    int next_safe = 0;
    for (int start = 1; start <= n; ++start) {
        if (next_safe != m) {
            res += n + 1 - safes[next_safe];
//            cout << start << " " << n + 1 - safes[next_safe] << endl;
        }
        if (start == safes[next_safe]) {
            ++next_safe;
        }
    }
    cout << res << endl;

    return 0;
}
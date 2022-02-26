//
// Created by Jonny Keane on 2/23/22.
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
    string grid[n];
    int max_heights[m];
    for (int i = 0; i < m; ++i) {
        max_heights[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#' && max_heights[j] == 0) {
                max_heights[j] = n - i;
            }
        }
    }
    for (auto max_height: max_heights) {
        cout << max_height << " ";
    }
    for (int i = 0; i < n; i += 2) {

    }

    return 0;
}
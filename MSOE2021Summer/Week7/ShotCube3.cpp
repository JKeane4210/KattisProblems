//
// Created by Jonny Keane on 7/9/21.
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

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        bitset<49> grid;
        grid.reset();
        for (int j = 0; j < 7; ++j) {
            string line;
            cin >> line;
            for (int k = 0; k < 7; ++k) {
                if (line[k] == 'X') {
                    grid[j * 7 + k] = true;
                }
            }
        }
        cout << minimalGame(grid, 0) << endl;
//        gridResults.clear();
    }

    return 0;
}
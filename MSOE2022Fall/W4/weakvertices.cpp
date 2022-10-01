//
// Created by keanej on 10/1/2022.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>
#define wgraph V<V<pii>>

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
    while (n != -1) {
        int grid[n][n];
        bool in_triangle[n];
        for (int i = 0; i < n; ++i) {
            in_triangle[i] = false;
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (in_triangle[i]) continue;
            bool found_triangle = false;
            for (int c1 = 0; c1 < n; ++c1) {
                if (found_triangle) break;
                if (i == c1) continue;
                for (int c2 = 0; c2 < n; ++c2) {
                    if (i == c2 || c1 == c2) continue;
                    if (grid[i][c1] && grid[i][c2] && grid[c1][c2]) {
                        in_triangle[i] = true;
                        in_triangle[c1] = true;
                        in_triangle[c2] = true;
                        found_triangle = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!in_triangle[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}
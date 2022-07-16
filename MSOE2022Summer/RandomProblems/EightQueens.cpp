//
// Created by Jonny Keane on 7/16/22.
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

int DELTAS[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string grid[8];
    for (int i = 0; i < 8; ++i) {
        cin >> grid[i];
    }
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (grid[i][j] == '*') {
                ++count;
                for (int k = 0; k < 8; ++k) {
                    if (k == i) continue;
                    if (grid[k][j] == '*') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                for (int k = 0; k < 8; ++k) {
                    if (k == j) continue;
                    if (grid[i][k] == '*') {
                        cout << "invalid" << endl;
                        return 0;
                    }
                }
                for (auto delta : DELTAS) {
                    int k = i + delta[0];
                    int l = j + delta[1];
                    while (k < 8 && k >= 0 && l < 8 && l >= 0) {
                        if (grid[k][l] == '*') {
                            cout << "invalid" << endl;
                            return 0;
                        }
                        k += delta[0];
                        l += delta[1];
                    }
                }
            }
        }
    }
    cout << (count == 8 ? "valid" : "invalid") << endl;

    return 0;
}

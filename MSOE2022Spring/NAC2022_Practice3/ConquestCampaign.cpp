//
// Created by keanej on 5/19/2022.
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

int DELTAS[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, n;
    cin >> r >> c >> n;
    set<pii> occ;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        occ.insert(mp(x, y));
    }
    int days = 1;
    set<pii> add;
    while (occ.size() != r * c) {
        for (auto p: occ) {
            for (auto delta: DELTAS) {
                int nx = p.first + delta[0];
                int ny = p.second + delta[1];
                if (nx >= 1 && nx <= r && ny >= 1 && ny <= c) {
                    add.insert(mp(nx, ny));
                }
            }
        }
        for (auto p: add) {
            occ.insert(p);
        }
        ++days;
    }
    cout << days << endl;

    return 0;
}
//
// Created by Jonny Keane on 1/22/22.
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

long nCr(int n, int r) {
    long res = 1;
    for (int i = n; i > max(r, n- r); --i) {
        res *= i;
    }
    for (int i = 1; i <= min(r, n - r); ++i) {
        res /= i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    graph g(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    long res = 0;
    for (int i = 0; i < g.size(); ++i) {
        if (g[i].size() >= 4) {
//            cout << i << endl;
            for (auto neighbor: g[i]) {
                int cross_matches = 0;
                for (auto n1: g[neighbor]) {
                    for (auto n2: g[i]) {
                        if (n1 == n2) {
                            ++cross_matches;
                        }
                    }
                }
                res += g[neighbor].size() - 1 - cross_matches;
                if (cross_matches > 0 && g[i].size() - 4 > 0) {
                    res += nCr(cross_matches, g[i].size() - 4);
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}
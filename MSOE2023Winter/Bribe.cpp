//
// Created by keanej on 2/23/2023.
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

double dp[17][1<<16] = {{-1}};

double fill(int bset, int cost, int converted, int to_convert, int m, const pair<double, int> * hm, int n) {
    if (dp[converted][bset] != -1) return dp[converted][bset];
    if (to_convert == 0) {
        dp[converted][bset] = 1.0;
        return 1.0;
    }
//    cout << bset << " " << converted << endl;
    double best = 0.0;
    for (int i = 0; i < n; ++i) {
        if ((bset & (1 << i)) == 0 && cost + hm[i].second <= m) {
            double p_res = hm[i].first * fill(bset | (1 << i), cost + hm[i].second, converted + 1, to_convert - 1, m, hm, n) +
                    (1.0 - hm[i].first) * fill(bset | (1 << i), cost + hm[i].second, converted, to_convert, m, hm, n);
            best = max(best, p_res);
        }
    }
    dp[converted][bset] = best;
    return best;
}

void solve() {
    int n, c, m;
    cin >> n >> c >> m;

    for (int i = 0; i <= c; ++i) {
        for (int j = 0; j < 1<<n; ++j) {
            dp[i][j] = -1;
        }
    }

    pair<double, int> hm[n];
    for (int i = 0; i < n; ++i) {
        int cost, prob;
        cin >> cost >> prob;
        hm[i] = {(double)prob / 100.0, cost};
    }

    double res = fill(0, 0, 0, c, m, hm, n);

    cout.precision(8);
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        solve();
    }

    return 0;
}
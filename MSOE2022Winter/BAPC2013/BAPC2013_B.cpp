//
// Created by Jonny Keane on 3/8/22.
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

map<pair<unsigned long, int>, double> memos;

double max_prob(const vpii & henchmen, int c, int m, bitset<16> visited) {
    if (memos.find(mp(visited.to_ulong(), c)) != memos.end()) {
//        cout << "memo" << endl;
//        cout << visited.to_ulong() << " " << c << endl;
        return memos[mp(visited.to_ulong(), c)];
    }
    if (c == 0) {
        return 1.0;
    }
//    cout << c << " " << m << endl;
    double res = 0.0;
    for (int i = 0; i < henchmen.size(); ++i) {
        if (!visited[i] && henchmen[i].first <= m) {
            bitset<16> new_visited(visited);
            new_visited[i] = true;
            res = max(res, (1.0 * henchmen[i].second / 100.0) * max_prob(henchmen, c - 1, m - henchmen[i].first, new_visited) +
                           (1.0 - 1.0 * henchmen[i].second / 100.0) * max_prob(henchmen, c, m - henchmen[i].first, new_visited));
        }
    }
    memos[mp(visited.to_ulong(), c)] = res;
//    cout << visited.to_ulong() << " " << c << " = " << res << endl;
//    cout << res << endl;
    return res;
}

void solve() {
    int n, c, m;
    cin >> n >> c >> m;
    vpii henchmen(n);
    memos.clear();
    for (int i = 0; i < n; ++i) {
        cin >> henchmen[i].first >> henchmen[i].second;
    }
    cout.precision(10);
    bitset<16> b;
    b.reset();
    cout << max_prob(henchmen, c, m, b) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        solve();
    }

    return 0;
}
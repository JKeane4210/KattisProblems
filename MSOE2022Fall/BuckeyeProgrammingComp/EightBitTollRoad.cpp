//
// Created by keanej on 10/30/2022.
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
    V<pair<int, long>> g[1000];
    for (int i = 0; i < 1000; ++i) {
       g[i] = V<pair<int, long>>();
    }
    for (int i = 0; i < n; ++i) {
        int a, b; long w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].pb(mp(b, w));
    }
    long shortest[256][1000];
    for (int i = 0; i < 256; ++i) {
        for (int j = 0; j < 1000; ++j) {
            shortest[i][j] = LONG_MAX;
        }
    }
    // dijkstras on the best configuration
    priority_queue<tuple<long, int, int>> pq; // {distance, mod, node}
    pq.push(make_tuple(0l, 0, 0));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        long dist = get<0>(top);
        int mod = get<1>(top);
        int node = get<2>(top);
        if (dist >= shortest[mod][node]) continue;
        if (node == 1 && mod == 0) {
            cout << 0 << " " << dist << endl;
            return 0;
        }
        shortest[mod][node] = dist;
        for (auto conn: g[node]) {
            long ndist = dist + conn.second;
            int nmod = (mod + conn.second) % 256;
            if (ndist >= shortest[nmod][conn.first]) continue;
            pq.push(make_tuple(ndist, nmod, conn.first));
        }
    }

    for (int i = 0; i < 256; ++i) {
        if (shortest[i][1] < LONG_MAX) {
            cout << i << " " << shortest[i][1] << endl;
            return 0;
        }
    }

    return 0;
}
//
// Created by keanej on 2/7/2023.
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

    int n, m, q;
    cin >> n >> m >> q;

    wgraph g = wgraph(n);
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        --a; --b;
        g[a].pb(mp(b, t));
        g[b].pb(mp(a, t));
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for (auto edge: g[0]) {
        pq.push(make_tuple(edge.second, edge.first, 0)); // w, trg, src
    }
    wgraph tree = wgraph(n);
    set<int> visited;
    while (visited.size() != n - 1) {
        auto top = pq.top();
        pq.pop();
        int trg = get<1>(top);
        if (visited.find(trg) != visited.end()) continue;
        cout << "adding edge" << get<0>(top) << " " << trg << "<->" << get<2>(top) << endl;
        visited.insert(trg);
        for (auto edge: g[trg]) {
            if (visited.find(edge.first) == visited.end())
                pq.push(make_tuple(edge.second, edge.first, trg));
        }
    }



    return 0;
}
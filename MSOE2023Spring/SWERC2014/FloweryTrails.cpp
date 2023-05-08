//
// Created by keanej on 5/8/2023.
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

    int n, m;
    cin >> n >> m;
    wgraph g(n, vpii());
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].pb({b, w});
        g[b].pb({a, w});
    }

    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    pq.push({0, 0, -1, -1}); // weight, trg, src
    int shortest[n];
    vpii prevs[n];
    for (int i= 0; i < n; ++i) { shortest[i] = INT_MAX; prevs[i] = vpii(); }
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        if (get<0>(top) > shortest[get<1>(top)]) continue;
        if (get<0>(top) == shortest[get<1>(top)]) {
            prevs[get<1>(top)].pb({get<2>(top), get<3>(top)});
            continue;
        } else {
            prevs[get<1>(top)].clear();
            if (get<2>(top) != -1)
                prevs[get<1>(top)].pb({get<2>(top), get<3>(top)});
        }
        shortest[get<1>(top)] = get<0>(top);
        for (auto conn: g[get<1>(top)]) {
            if (get<0>(top) + conn.second > shortest[conn.first]) continue;
            pq.push({get<0>(top) + conn.second, conn.first, get<1>(top), conn.second});
        }
    }
//    cout << shortest[n - 1] << endl;
//    for (int i = 0; i < n; ++i) {
//        cout << i << ": " << shortest[i] << endl;
//        for (auto v: prevs[i]) {
//            cout << v.first << "(" << v.second << ") ";
//        }
//        cout<< endl;
//    }
    set<int> visited;
    int total = 0;
    queue<int> q;
    q.push(n - 1);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (visited.find(top) != visited.end()) continue;
        visited.insert(top);
         for (auto p: prevs[top]) {
//            cout << top << "->" << p.first << " " << p.second << endl;
            total += p.second;
            q.push(p.first);
        }
    }
    cout << 2 * total << endl; // 2 *
    
    return 0;
}
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

    int n, m;
    cin >> n >> m;
    vi conns[n];
    bool connected[n];
    for (int i = 0; i < n; ++i) {
        connected[i] = i == 0;
        conns[i] = vi();
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        conns[a].pb(b);
        conns[b].pb(a);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        connected[front] = true;
        for (auto conn: conns[front]) {
            if (connected[conn]) continue;
            q.push(conn);
        }
    }
    set<int> disconnected;
    for (int i = 0; i < n; ++i) {
        if (!connected[i]) {
            disconnected.insert(i + 1);
        }
    }
    if (disconnected.empty()) {
        cout << "Connected" << endl;
    } else {
        for (auto v: disconnected) {
            cout << v << endl;
        }
    }

    return 0;
}
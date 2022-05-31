//
// Created by keanej on 5/30/2022.
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

    int n, k, c;
    cin >> n >> k >> c;
    int latest_contact[n];
    fill(latest_contact, latest_contact + n, 0);

    vector<pii> conns[n]; // {person, day}
    fill(conns, conns + n, vector<pii>());

    for (int i = 0; i < c; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        --a; --b;
        latest_contact[a] = max(latest_contact[a], d);
        latest_contact[b] = max(latest_contact[b], d);
        conns[a].pb(mp(b, d));
        conns[b].pb(mp(a, d));
    }

    set<int> quarantine;

    queue<pii> q;
    for (int i = 0; i < n; ++i) {
        if (latest_contact[i] == 1) {
            q.push(mp(i, 1));
        }
    }
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (top.second == k + 2) break;
        for (auto conn: conns[top.first]) {
            if (latest_contact[top.first] == top.second && conn.second == top.second) { // if this person was potentially infected on this day
                if (conn.second == k) {
                    quarantine.insert(conn.first);
                }
                q.push(mp(conn.first, conn.second + 1));
            }
        }
    }

    cout << quarantine.size() << endl;
    for (int person: quarantine) {
        cout << person + 1 << endl;
    }

    return 0;
}
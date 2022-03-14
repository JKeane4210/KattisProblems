//
// Created by Jonny Keane on 3/7/22.
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

/// A step forward in dijkstra's algorithm
/// \tparam W The type of the weight (int/double)
template<typename W>
class DijkstrasStep {
public:
    int nodeID;
    W totalDist;
    int prev;

    DijkstrasStep(int nodeID, W totalDist, int prev) : nodeID(nodeID), totalDist(totalDist), prev(prev) {};

    friend bool operator<(const DijkstrasStep<W> &a, const DijkstrasStep<W> &b) {
        return a.totalDist > b.totalDist;
    }
};

void solve() {
    int n, m, t, s, g, h;
    cin >> n >> m >> t >> s >> g >> h;


    vector<int> prevs[n + 1];
    int minTable[n + 1];
    for (int i = 0; i <= n; ++i) {
        prevs[i] = vi();
        minTable[i] = INT_MAX;
    }
    wgraph roads(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        roads[a].pb(mp(b, d));
        roads[b].pb(mp(a, d));
    }

    set<int> poss_destinations;
    for (int i = 0; i < t; ++i) {
        int val;
        cin >> val;
        poss_destinations.insert(val);
    }

    priority_queue<DijkstrasStep<int>> pq;
    pq.push(DijkstrasStep<int>(s, 0, -1));
    while (!pq.empty()) {

        DijkstrasStep<int> shortest = pq.top();
        pq.pop();
        if (shortest.totalDist > minTable[shortest.nodeID]) {
            continue;
        } else if (shortest.totalDist == minTable[shortest.nodeID]) {
            prevs[shortest.nodeID].pb(shortest.prev);
        } else {
            prevs[shortest.nodeID].clear();
            prevs[shortest.nodeID].pb(shortest.prev);
            minTable[shortest.nodeID] = shortest.totalDist;
            for (const auto &p: roads[shortest.nodeID]) {
                pq.push(DijkstrasStep<int>(p.first, shortest.totalDist + p.second, shortest.nodeID));
            }
        }
    }

    pii e1 = mp(g, h);
    pii e2 = mp(h, g);
    for (auto dest: poss_destinations) {
        queue<pii> q;
        q.push(mp(dest, -1)); // {curr, prev}
        bool found = false;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
//            cout << top.first << " " << top.second << endl;
            if (top == e1 || top == e2) {
                found = true;
                break;
            }
            if (top.first == -1) continue;
            for (auto prev: prevs[top.first]) {
                q.push(mp(prev, top.first));
            }
        }
        if (found) {
            cout << dest << " ";
        }
    }
    cout << endl;
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
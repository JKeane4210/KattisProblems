//
// Created by Jonny Keane on 3/29/22.
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

class DijkstrasStep {
public:
    pii nodeID;
    int val;
    int totalDist;

    DijkstrasStep(pii nodeID, int val, int totalDist) : nodeID(nodeID), val(val), totalDist(totalDist) {};

    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int grid[n][n];
    vpii num_locs[k + 1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int val; cin >> val;
            num_locs[val].pb(mp(i,j));
        }
    }

    int shortest[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            shortest[i][j] = INT_MAX;
        }
    }
    priority_queue<DijkstrasStep> pq;
    for (auto p: num_locs[1]) {
        pq.push(DijkstrasStep(p, 1, 0));
    }
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (top.val == k) {
            cout << top.totalDist << endl;
            return 0;
        }
        if (top.totalDist < shortest[top.nodeID.first][top.nodeID.second]) {
//            cout << top.nodeID.first << " " << top.nodeID.second << endl;
            shortest[top.nodeID.first][top.nodeID.second] = top.totalDist;
            for (auto p: num_locs[top.val + 1]) {
                pq.push(DijkstrasStep(p, top.val + 1, top.totalDist + abs(top.nodeID.first - p.first) + abs(top.nodeID.second - p.second)));
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
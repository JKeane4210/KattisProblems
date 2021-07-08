//
// Created by Jonny Keane on 7/5/21.
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

class DijkstrasStep {
public:
    pair<int, int> nodeID;
    int totalDist;

    /// Initializes node ID and total distance
    /// \param nodeID Node ID
    /// \param totalDist Total distance
    DijkstrasStep(pair<int, int> nodeID, int totalDist) : nodeID(nodeID), totalDist(totalDist) {};

    /// Comparator of DijkstrasSteps for use in priority queue
    /// \param a A step
    /// \param b Another step
    /// \return If a is "lesser"
    /// \tparam The type of the weight (int/double)
    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

int shortestPath() {
    map<pair<int, int>, int> shortestPathTable;
    map<pair<int, int>, vector<pair<int, int>>> connections;
    int s;
    cin >> s;
    int x = 0, y = 0;
    shortestPathTable[make_pair(0, 0)] = INT_MAX;
    connections[make_pair(0, 0)] = vector<pair<int, int>>();
    for (int i = 0; i < s; ++i) {
        string dir;
        cin >> dir;
        pair<int, int> prev = make_pair(x, y);
        pair<int, int> next;
        switch (dir[0]) {
            case 'N':
                next = make_pair(x, ++y);
                break;
            case 'S':
                next = make_pair(x, --y);
                break;
            case 'E':
                next = make_pair(++x, y);
                break;
            case 'W':
                next = make_pair(--x, y);
                break;
        }
        shortestPathTable[next] = INT_MAX;
        if (connections.find(next) == connections.end()) {
            connections[next] = vector<pair<int, int>>();
        }
        connections[next].emplace_back(prev);
        connections[prev].emplace_back(next);
    }
    pair<int, int> dest = make_pair(x, y);
    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(make_pair(0, 0), 0));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (shortestPathTable[top.nodeID] < top.totalDist) continue;
        shortestPathTable[top.nodeID] = top.totalDist;
        if (top.nodeID == dest) return shortestPathTable[top.nodeID];
        for (auto conn: connections[top.nodeID]) {
            pq.push(DijkstrasStep(conn, top.totalDist + 1));
        }
    }

    return shortestPathTable[dest];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << shortestPath() << endl;
    }

    return 0;
}
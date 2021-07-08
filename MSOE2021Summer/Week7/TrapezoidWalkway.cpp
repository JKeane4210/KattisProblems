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

double DOLLARS_PER_CM2 = 0.02;

class DijkstrasStep {
public:
    int nodeID;
    int totalDist; // store it and then divide by 2 at the end

    /// Initializes node ID and total distance
    /// \param nodeID Node ID
    /// \param totalDist Total distance
    DijkstrasStep(int nodeID, int totalDist) : nodeID(nodeID), totalDist(totalDist) {};

    /// Comparator of DijkstrasSteps for use in priority queue
    /// \param a A step
    /// \param b Another step
    /// \return If a is "lesser"
    /// \tparam The type of the weight (int/double)
    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

double smallestArea(int n) {
    map<int, vector<pair<int, int>>> conns;
    map<int, int> shortestPathTable;
    for (int i = 0; i < n; ++i) {
        int a, b, h;
        cin >> a >> b >> h;
        shortestPathTable[a] = INT_MAX;
        shortestPathTable[b] = INT_MAX;
        if (conns.find(a) == conns.end()) {
            conns[a] = vector<pair<int, int>>();
        }
        conns[a].push_back(make_pair(b, h));
        if (conns.find(b) == conns.end()) {
            conns[b] = vector<pair<int, int>>();
        }
        conns[b].push_back(make_pair(a, h));
    }
    int porch, gazebo;
    cin >> porch >> gazebo;
    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(porch, 0));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (top.totalDist >= shortestPathTable[top.nodeID]) continue;
        shortestPathTable[top.nodeID] = top.totalDist;
        if (top.nodeID == gazebo) {
            return (double)shortestPathTable[top.nodeID] / 2.0 * DOLLARS_PER_CM2;
        }
        for (auto conn: conns[top.nodeID]) {
            pq.push(DijkstrasStep(conn.first, top.totalDist + (top.nodeID + conn.first) * conn.second));
        }
    }
    return (double)shortestPathTable[gazebo] / 2.0 * DOLLARS_PER_CM2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n != 0) {
        printf("%.2f\n", smallestArea(n));
        cin >> n;
    }

    return 0;
}
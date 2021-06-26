//
// Created by Jonny Keane on 6/20/21.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int leftAngleDelta(int in, int out) {
    if (out >= in) {
        return out - in;
    } else {
        return 360 - in + out;
    }
}

int rightAngleDelta(int in, int out) {
    if (in >= out) {
        return in - out;
    } else {
        return 360 - out + in;
    }
}

/// Dijkstra's Algorithm classes
namespace DijkstrasAlg {
    /// Enumerates infinity
    enum {
        INF = INT_MAX
    };

    /// A step forward in dijkstra's algorithm
    /// \tparam W The type of the weight (int/double)
    template<typename W>
    class DijkstrasStep {
    public:
        int nodeID;
        W totalDist;
        int incomingAngle;

        /// Initializes node ID and total distance
        /// \param nodeID Node ID
        /// \param totalDist Total distance
        DijkstrasStep(int nodeID, W totalDist, int incomingAngle) :
            nodeID(nodeID), totalDist(totalDist), incomingAngle(incomingAngle) {};

        /// Comparator of DijkstrasSteps for use in priority queue
        /// \param a A step
        /// \param b Another step
        /// \return If a is "lesser"
        /// \tparam The type of the weight (int/double)
        friend bool operator< (const DijkstrasStep<W> &a, const DijkstrasStep<W> &b) {
            return a.totalDist > b.totalDist;
        }
    };

    /// Class to hold Dijsktra's Algorithm
    /// \tparam W The type of the weight (int/double)
    template<typename W>
    class Dijkstras {
    public:
        map<int, pair<W, int>>* graph;
        W* shortestPathTable;
        int numNodes;

        /// Initializes the Dijkstras object
        /// \param graph The assembled graph
        /// \param numNodes The number of nodes in the graph
        Dijkstras(map<int, pair<W, int>>* graph, int numNodes) :
                graph(graph), numNodes(numNodes) {
            shortestPathTable = new W[numNodes];
            for (int i = 0; i < numNodes; ++i) {
                shortestPathTable[i] = INF;
            }
        }

        /// Runs Dijkstra's Algorithm on the graph
        /// \param start The node to start at
        int dijkstras(int start, int leftAngle, int rightAngle, int end, int incomingAngle = -1) {
            priority_queue<DijkstrasStep<W>> pq;
            pq.push(DijkstrasStep<W>(start, 0, incomingAngle));
            //MAIN LOOP
            while (!pq.empty()) {
                DijkstrasStep<W> shortest = pq.top();
                pq.pop();
                if (shortest.totalDist < shortestPathTable[shortest.nodeID]) {
                    shortestPathTable[shortest.nodeID] = shortest.totalDist;
                }
                if (shortest.nodeID == end) {
                    return shortest.incomingAngle;
                }
                map<int, pair<W, int>> newPaths;
                cout << shortest.nodeID << endl;
                for (const auto& p: graph[shortest.nodeID]) {
                    if (shortest.incomingAngle == -1 ||
                        leftAngleDelta((shortest.incomingAngle + 180) % 360, p.second.second) <= leftAngle ||
                        rightAngleDelta((shortest.incomingAngle + 180) % 360, p.second.second) <= rightAngle) {
                        pq.push(DijkstrasStep<W>(p.first, shortest.totalDist + p.second.first, graph[p.first][shortest.nodeID].second));
                    } else {
                        newPaths.insert(p);
                        cout << "\t" << p.first << ": (" << p.second.first << ", " << p.second.second << ")" << endl;
                    }
                }
                graph[shortest.nodeID] = newPaths;
                cout << endl;
            }
            return -1;
        }
    };
}

using namespace DijkstrasAlg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d, a_1, a_2;
    cin >> n >> d >> a_1 >> a_2;
    map<int, pair<int, int>>graph[n]; // node : weight, incoming angle
    map<int, pair<int, int>> graph2[n];
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int d_j, t_j, a_j;
            cin >> d_j >> t_j >> a_j;
            graph[i][d_j - 1] = make_pair(t_j, a_j);
            graph2[i][d_j - 1] = make_pair(t_j, a_j);
        }
    }
    Dijkstras<int> dij(graph, n);
    int incoming = dij.dijkstras(0, a_1, a_2, d - 1);
    if (dij.shortestPathTable[d - 1] == INF) {
        cout << "impossible" << endl;
        return 0;
    }
    int toThere = dij.shortestPathTable[d - 1];
    Dijkstras<int> dij2(graph2, n);
    dij2.dijkstras(d - 1, a_1, a_2, 0, incoming);
    if (dij2.shortestPathTable[0] == INF) {
        cout << "impossible" << endl;
        return 0;
    }
    int andBack = dij2.shortestPathTable[0];
    cout << toThere + andBack << endl;

    return 0;
}
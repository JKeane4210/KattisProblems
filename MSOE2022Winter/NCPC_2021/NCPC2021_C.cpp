//
// Created by Jonny Keane on 2/11/22.
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
    int nodeID;
    int prev;
    int totalDist;

    DijkstrasStep(int nodeID, int prev, int totalDist) : nodeID(nodeID), prev(prev), totalDist(totalDist) {};

    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

namespace MaxFlow {
    /// A node in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Node;
    /// A connection in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Connection;
    /// A flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class FlowGraph;

    /// Enumerates the sink and source nodes
    enum flowGraphNodes {
        SOURCE = -1,
        SINK = -2
    };

    /// A node in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Node {
    public:
        /// The connections and where they lead (mapped for O(logn) indexing
        map<int, Connection<W>*> conns;
    };

    /// A connection in a flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class Connection {
    public:
        int from;
        int to;
        W fwCap;
        W bwCap;

        /// Initializes connection
        /// \param from Index of from node
        /// \param to Index of to node
        /// \param fwCap Capacity going forwards on connection
        /// \param bwCap Capacity going backwards on connection
        Connection(int from, int to, W fwCap, W bwCap) :
                from(from), to(to), fwCap(fwCap), bwCap(bwCap) {}

        /// Send flow down a connection
        /// \param flow The amount of flow to send
        /// \param from_ Where the flow is originating from
        void sendFlow(W flow, int from_) {
            if (from_ == from) {
                fwCap -= flow;
                bwCap += flow;
            } else {
                fwCap += flow;
                bwCap -= flow;
            }
        }

        /// The to node for a given direction
        /// \param from_ The from node
        /// \return The to node for a given direction
        int to_(int from_) {
            return from_ == from ? to : from;
        }

        /// The forward capacity for a given direction
        /// \param from_ The from node
        /// \return The forward capacity for a given direction
        W fwCap_(int from_) {
            return from_ == from ? fwCap : bwCap;
        }
    };

    /// A flow graph
    /// \tparam W The type of the capacity (int/double)
    template<typename W>
    class FlowGraph {
    public:
        map<int, Node<W>> nodes;

        /// Initializes just the source and sink nodes
        FlowGraph() {
            nodes[SOURCE] = Node<W>();
            nodes[SINK] = Node<W>();
        }

        /// Initializes the source, sink, and a range of nodes
        /// \param start
        /// \param end
        FlowGraph(int start, int end) : FlowGraph() {
            for (int i = start; i <= end; ++i) {
                nodes[i] = Node<W>();
            }
        }

        /// Adds connection between nodes
        /// \param from From node
        /// \param to To node
        /// \param fwCap Forward capacity
        /// \param bwCap Backward capacity
        void addConnection(int from, int to, W fwCap, W bwCap) {
            auto* conn = new Connection<W>(from, to, fwCap, bwCap);
            nodes[from].conns[to] = conn;
            nodes[to].conns[from] = conn;
        }

        /// Returns the maximum flow of a flow graph
        /// \return The maximum flow of a graph
        int fordFulkerson() {
            W maxFlow = 0;
            W pathFlow = bfs();
            while (pathFlow != -1) {
                maxFlow += pathFlow;
                sendFlow(pathFlow);
                pathFlow = bfs();
            }
            return maxFlow;
        }

    private:
        map<int, int> parents;
        /// Sends flow down the path found by the bfs
        /// \param pathMaxFlow The path flow found
        void sendFlow(W pathMaxFlow) {
            int curr = SINK;
            while (curr != SOURCE) {
                int temp = parents[curr];
                nodes[temp].conns[curr]->sendFlow(pathMaxFlow, temp);
                curr = temp;
            }
        }

        /// Searches for sink starting from source
        /// \return The flow for a path source to sink (-1 if fails)
        W bfs() {
            parents.clear();
            set<int> visited;
            queue<pair<pair<int, int>, Connection<W>*>> q;
            visited.insert(SOURCE);
            for (auto conn: nodes[SOURCE].conns) {
                if (conn.second->fwCap_(SOURCE) > 0) {
                    q.push(make_pair(make_pair(SOURCE, conn.second->fwCap_(SOURCE)), conn.second));
                    parents[conn.second->to_(SOURCE)] = SOURCE;
                    visited.insert(conn.second->to_(SOURCE));
                }
            }
            while (!q.empty()) {
                auto top = q.front();
                q.pop();
                // --- defining from and to ---
                int from = top.first.first;
                W maxFlow = top.first.second;
                Connection<W>* conn = top.second;
                int to = conn->to_(from);
                // ----------------------------
                if (to == SINK) return maxFlow;
                for (auto nextConn: nodes[to].conns) {
                    if (visited.count(nextConn.second->to_(to)) == 0 && nextConn.second->fwCap_(to) > 0) {
                        visited.insert(nextConn.second->to_(to));
                        parents[nextConn.second->to_(to)] = to;
                        q.push(make_pair(make_pair(to, min(maxFlow, nextConn.second->fwCap_(to))), nextConn.second));
                    }
                }
            }
            return -1;
        }

        /// contents for if dfs is needed
        set<int> dfs_visited;

        /// Searches for sink starting from source (depth search)
        /// \return The flow for a path to sink (-1 if fails)
        int dfs() {
            dfs_visited.clear();
            dfs_visited.insert(SOURCE);
            return dfs(SOURCE, INT_MAX);
        }

        /// Recursive portion of dfs
        /// \return The flow for a path to sink (-1 if fails)
        int dfs(int curr, int min_) {
            if (curr == SINK) return min_;
            for (auto nextConn: nodes[curr].conns) {
                int to = nextConn.second->to_(curr);
                W fwCap = nextConn.second->fwCap_(curr);
                if (dfs_visited.count(to) == 0 && fwCap > 0) {
                    dfs_visited.insert(to);
                    parents[to] = curr;
                    int search = dfs(to, min(min_, fwCap));
                    if (search != -1) {
                        return search;
                    }
                }
            }
            return -1;
        }
    };
}

using namespace MaxFlow;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    graph G(n);
    int times[n];
    int shortestPaths[n];
    vector<int> prevs[n];
    for (int i = 0; i < n; ++i) {
        cin >> times[i];
        shortestPaths[i] = INT_MAX;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    // dijkstras to get the shortest path from 1 to n
    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(0, -1, times[0]));
    //MAIN LOOP
    while (!pq.empty()) {
        DijkstrasStep shortest = pq.top();
        pq.pop();
        if (shortest.totalDist == shortestPaths[shortest.nodeID]) {
            prevs[shortest.nodeID].pb(shortest.prev);
        }
        if (shortest.totalDist >= shortestPaths[shortest.nodeID]) {
            continue;
        }
        shortestPaths[shortest.nodeID] = shortest.totalDist;
        prevs[shortest.nodeID].clear();
        prevs[shortest.nodeID].pb(shortest.prev);
        for (auto conn: G[shortest.nodeID]) {
            pq.push(DijkstrasStep(conn, shortest.nodeID, shortest.totalDist + times[conn]));
        }
    }
    // max flow of remaining edges to see minimal cut group
    set<pii> conns;
    FlowGraph<int> flowGraph(0, n - 1);
    queue<int> q;
    q.push(n - 1);
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        if (front == -1) continue;
        for (auto prev: prevs[front]) {
            auto conn = make_pair(prev, front);
            if (conns.find(conn) == conns.end() && prev != -1) {
                conns.insert(make_pair(prev, front));
                flowGraph.addConnection(prev == 0 ? SOURCE : prev, front == n - 1 ? SINK : front, 1, 0);
                q.push(prev);
                cout << conn.first << " " << conn.second << endl;
            }
        }
    }
    flowGraph.fordFulkerson();
    // get what edges should be blocked
    set<int> cutEdgeVertices;
    set<pii> cutEdges;
    queue<int> q2;
    q2.push(SOURCE);
    while (!q2.empty()) {
        auto front = q2.front();
        q2.pop();
        for (auto conn: flowGraph.nodes[front].conns) {
            cout << front << "->" << conn.first << endl;
            if (conn.second->fwCap_(front) == 0) {
                cutEdgeVertices.insert(front);
                cutEdgeVertices.insert(conn.first);
                cutEdges.insert(make_pair(front, conn.first));
            } else {
                q2.push(conn.first);
            }
        }
    }
    for (auto v: cutEdgeVertices) {
        cout << v << endl;
    }

    return 0;
}
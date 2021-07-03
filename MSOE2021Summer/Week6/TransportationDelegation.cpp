//
// Created by Jonny Keane on 6/27/21.
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

/// Maximum flow classes
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
        /// The connections and where they lead (mapped for O(logn) indexing)
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
            addRange(start, end);
        }

        void addRange(int start, int end) {
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
            W pathFlow = dfs();
            while (pathFlow != -1) {
                maxFlow += pathFlow;
                sendFlow(pathFlow);
                pathFlow = dfs();
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

        /// Searches for sink starting from source (breadth first)
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
//                if (to == SOURCE) return -1;
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

        // contents for if dfs is needed
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
    int s, r, f, t;
    cin >> s >> r >> f >> t;
    FlowGraph<int> flowGraph(0, s + 2 * t - 1);
    set<string> suppliers;
    set<string> factories;
    set<string> others;
    map<string, int> states;
    int ind = 2 * t;
    for (int i = 0; i < r; ++i) {                                                         // suppliers
        string state;
        cin >> state;
        states[state] = ind++;
        flowGraph.addConnection(SOURCE, states[state], 1, 0);
        suppliers.insert(state);
    }
    for (int i = 0; i < f; ++i) {                                                        // factories
        string state;
        cin >> state;
        states[state] = ind++;
        flowGraph.addConnection(states[state], SINK, 1, 0);
        factories.insert(state);
    }
    for (int i = 0; i < t; ++i) {                                                       // transportation
        int conns;
        cin >> conns;
        flowGraph.addConnection(2 * i, 2 * i + 1, 1, 0);
        for (int j = 0; j < conns; ++j) {
            string state;
            cin >> state;
            if (suppliers.count(state) != 0) {
                flowGraph.addConnection(states[state], 2 * i, 1, 0);
            } else if (factories.count(state) != 0) {
                flowGraph.addConnection(2 * i + 1, states[state], 1, 0);
            } else {
                if (others.count(state) == 0) {
                    states[state] = ind++;
                    others.insert(state);
                }
                flowGraph.addConnection(states[state], 2 * i, 1, 0);
                flowGraph.addConnection(2 * i + 1, states[state], 1, 0);
            }
        }
    }

    cout << flowGraph.fordFulkerson() << endl;
    return 0;
}

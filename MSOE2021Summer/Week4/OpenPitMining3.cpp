//
// Created by Jonny Keane on 6/18/21.
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

namespace MaxFlow {
    template<typename W>
    class Connection;
    template<typename W>
    class Node;
    template<typename W>
    class FlowGraph;

    enum flowGraphNodes {
        SOURCE = -1,
        SINK = -2
    };

    template<typename W>
    class Node {
    public:
        map<int, Connection<W>*> conns;
    };

    template<typename W>
    class Connection {
    public:
        int from;
        int to;
        W fwCap;
        W bwCap;
        Connection(int from, int to, W fwCap, W bwCap) :
                from(from), to(to), fwCap(fwCap), bwCap(bwCap) {}

        void sendFlow(W flow, int from_) {
            if (from_ == from) {
                fwCap -= flow;
                bwCap += flow;
            } else {
                fwCap += flow;
                bwCap -= flow;
            }
        }

        int to_(int from_) {
            return from_ == from ? to : from;
        }

        W fwCap_(int from_) {
            return from_ == from ? fwCap : bwCap;
        }
    };

    template<typename W>
    class FlowGraph {
    public:
        FlowGraph() {
            nodes[SOURCE] = Node<W>();
            nodes[SINK] = Node<W>();
        }

        FlowGraph(int start, int end) : FlowGraph() {
            for (int i = start; i <= end; ++i) {
                nodes[i] = Node<W>();
            }
        }

        map<int, Node<W>> nodes;
        map<int, int> parents;

        void addConnection(int from, int to, W fwCap, W bwCap) {
            auto* conn = new Connection<W>(from, to, fwCap, bwCap);
            nodes[from].conns[to] = conn;
            nodes[to].conns[from] = conn;
        }

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
        void sendFlow(W pathMaxFlow) {
            int curr = SINK;
            while (curr != SOURCE) {
                int temp = parents[curr];
                nodes[temp].conns[curr]->sendFlow(pathMaxFlow, temp);
                curr = temp;
            }
        }

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
    };
}

using namespace MaxFlow;

int main() {
    int n;
    cin >> n;
    FlowGraph<int> flowGraph(1, n);
    int maxYield = 0;
    for (int i = 1; i <= n; ++i) {
        int v, c, m;
        cin >> v >> c >> m;
        int w = v - c;
        if (w > 0) {
            flowGraph.addConnection(SOURCE, i, w, 0);
            maxYield += w;
        } else {
            flowGraph.addConnection(i, SINK, -w, 0);
        }
        for (int j = 0; j < m; ++j) {
            int block;
            cin >> block;
            flowGraph.addConnection(block, i, INT_MAX, 0);
        }
    }
    cout << maxYield - flowGraph.fordFulkerson() << endl;
}
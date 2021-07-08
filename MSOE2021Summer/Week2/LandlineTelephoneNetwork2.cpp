//
// Created by Jonny Keane on 5/30/21.
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

/**
* Class to represent a node with a representative
* and a n
*/
template <typename T>
class Node {
public:
    long rep;
    long size;
    T data;

    /**
     * Constructor to initialize the Node
     * @param rep_ the representative
     * @param size_ the n of the set it's in
     * @param data_ the data stored in the Node
     */
    Node(long rep_, long size_, T data_) {
        rep = rep_;
        size = size_;
        data = data_;
    }
    /**
     * Default constructor
     */
    Node() {
        rep = 0;
        size = 0;
        data = 0;
    }
};

/**
 * Edge between two nodes
 */
class Edge {
public:
    long a;
    long b;
    long weight;

    /**
     * Constructor to initialize the Edge
     * @param a_ node A
     * @param b_ node B
     * @param w_ the weight between
     */
    Edge(long a_, long b_, long w_) {
        a = a_;
        b = b_;
        weight = w_;
    }

    /**
     * Operator for less than between two edges
     * @param a
     * @param b
     * @return
     */
    friend bool operator<(const Edge& a, const Edge& b);
};

/**
 * Operator for priority queue to compare two edges and sort
 * @param a a edge
 * @param b the other edge
 * @return boolean saying which is less than the other
 */
bool operator<(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}


/**
 * Class for a UnionFind structure
 */
template <typename T>
class UnionFind {
public:
    vector<Node<T>> data;
    long size;

    /**
     * Constructor for the UnionFind
     * @param size the n of the data
     */
    explicit UnionFind(long size_) {
        size = size_;
        vector<Node<T>> temp(size);
        data = temp;
    }

    /**
     * Joins two nodes through union find
     * @param a the first node index
     * @param b the second node index
     */
    void unite(long a, long b) {
        a = find(a);
        b = find(b);
        if (data[a].n < data[b].n) {
            data[b].rep = data[a].rep;
            data[b].n += data[a].n;
        } else {
            data[a].rep = data[b].rep;
            data[a].n += data[b].n;
        }
    }

    /**
     * returns the ID of the representative of a node
     * @param node the node to give the representative of
     * @return the representative of the node
     */
    long find(long node) {
        while (node != data[node].rep) {
            node = data[node].rep;
        }
        return data[node].rep;
    }

    /**
     * Checks if two components are from the same set
     * @param a the first node
     * @param b the second node
     * @return if the two components are from the same set
     */
    bool same(long a, long b) {
        return find(a) == find(b);
    }

    /**
     * Performs Kruskal's Algorithm to create the minimum spanning tree
     * of a graph
     * @param pq the priority queue of all of the edges in the graph
     * @param f the function to be executed for each edge added in spanning tree
     */
    bool kruskals(priority_queue<Edge> pq, const function<void(Edge edge, Node<T> a, Node<T> b)>& f = nullptr) {
        int connectionsMade = 0;
        while(!pq.empty() && connectionsMade < size - 1 ) {
            Edge top = pq.top();
            pq.pop();
            long a = top.a, b = top.b;
            if (!same(a, b)) {
                unite(a, b);
                if (f != nullptr) {
                    f(top, data[a], data[b]);
                }
                ++connectionsMade;
            }
        }
        return connectionsMade == size - 1;
    }
};

long long totalWeight = 0;

void increaseWeight(Edge e, Node<int> a, Node<int> b) {
    totalWeight += e.weight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, p;
    cin >> n >> m >> p;


    map<int, set<Edge>> insecure;
    for (int i = 0; i < p; ++i) {
        int b;
        cin >> b;
        set<Edge> edges;
        insecure[b] = edges;
    }

    if (n == 2 && p == 2) {
        int a, b, w;
        cin >> a >> b >> w;
        cout << w << endl;
        return 0;
    }
    UnionFind<int> unionFind(n);
    priority_queue<Edge> edges;
    for (int i = 0; i < n; ++i) {
        Node<int> node(i, 1, i);
        unionFind.data[i] = node;
    }
    for (int j = 0; j < m; ++j) {
        int a, b, w;
        cin >> a >> b >> w;
        bool aInsecure = insecure.find(a) != insecure.end();
        bool bInsecure = insecure.find(b) != insecure.end();
        if (!aInsecure || !bInsecure) {
            Edge edge(a - 1, b - 1, w);
            if (aInsecure) {
                insecure[a].insert(edge);
            } else if (bInsecure) {
                insecure[b].insert(edge);
            } else {
                edges.push(edge);
            }
        }
    }
    for (auto& building: insecure) {
        if (!building.second.empty()) {
            auto end = building.second.end();
            --end;
            edges.push(*end);
        }
    }

    if (unionFind.kruskals(edges, increaseWeight)) {
        cout << totalWeight << endl;
    } else {
        cout << "impossible" << endl;
    }
    return 0;
}

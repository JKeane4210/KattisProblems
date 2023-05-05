//
// Created by keysers on 5/3/23.
//

//
// Created by keysers on 5/3/23.
//

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define V vector
#define vi V<int>
#define pii pair<int, int>
#define graph V<vi>
#define wgraph V<V<pii>>
#define nl '\n'
using namespace std;

template <typename T>
class Node {
public:
    ll rep;
    ll size;
    ll starter;
    T data;

    Node(long rep, long size, T data, ll starter) : rep(rep), size(size), data(data), starter(starter) {}

    Node() : rep(0), size(0), data(0) {}
};

class Edge {
public:
    ll a;
    ll b;
    ll weight;

    Edge(ll a, ll b, ll w) : a(a), b(b), weight(w) {}

    friend bool operator<(const Edge& a, const Edge& b);
};

bool operator<(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}


template <typename T>
class UnionFind {
public:
    vector<Node<T>> data;
    long size;

    explicit UnionFind(long size_) {
        size = size_;
        vector<Node<T>> temp(size);
        data = temp;
    }

    void unite(long a, long b) {
        a = find(a);
        b = find(b);
        if (data[a].size < data[b].size) {
            data[a].rep = data[b].rep;
            data[b].size += data[a].size;
            data[a].starter = max(data[a].starter, data[b].starter);
            data[b].starter = max(data[a].starter, data[b].starter);

        } else {
            data[b].rep = data[a].rep;
            data[a].size += data[b].size;
            data[a].starter = max(data[a].starter, data[b].starter);
            data[b].starter = max(data[a].starter, data[b].starter);
        }
    }

    long find(long node) {
        while (node != data[node].rep) {
            node = data[node].rep;
        }
        return data[node].rep;
    }

    bool same(long a, long b) {
        return find(a) == find(b);
    }

    void kruskals(priority_queue<Edge> pq, ll s, const function<void(Edge edge, Node<T> a, Node<T> b)>& f = nullptr) {
        int connectionsMade = 0;
        while(connectionsMade < size - s) {
            Edge top = pq.top();
            pq.pop();
//            cout << "edge " << top.weight << endl;
            long a = top.a, b = top.b;
            if (!same(a, b) && ((data[find(b)].starter == -1) || ((data[find(a)].starter == -1)))) {
                unite(a, b);
                if (f != nullptr) {
                    f(top, data[a], data[b]);
                }
                ++connectionsMade;
            }
        }
    }
};

void solve() {
    ll n, m, l, s;
    cin >> n >> m >> l >> s;
    UnionFind<ll> uf(n);
    priority_queue<Edge> pq;
    vector<vector<pair<ll, ll>>> conns(n, vector<pair<ll, ll>>());
    for (int i = 0; i < n; ++i) {
        uf.data[i] = Node<ll>(i, 1, i, -1);
    }
    set<ll> starters;
    for (int i = 0; i < s; ++i) {
        ll starter;
        cin >> starter;
        --starter;
        uf.data[starter].starter = starter;
        starters.insert(starter);
    }

    for (int i = 0;i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        pq.push(Edge(a, b, w));
    }

    ll total = 0;

    vector<Edge> mst_edges;
    uf.kruskals(pq, s, [&total](Edge e, Node<ll> a, Node<ll> b){
        total += e.weight;
//        cout << e.weight << endl;
    });

//    ll total = 0;
//
//    int connectionsMade = 0;
//    while(connectionsMade < n - s) {
//        Edge top = pq.top();
//        pq.pop();
//        ll a = top.a, b = top.b;
//        if (!uf.same(a, b)) {
//            uf.unite(a, b);
//            total += top.weight;
//            starters.insert(a);
//            starters.insert(b);
//            for (auto conn: conns[b]) {
//                if (starters.find(conn.first) == starters.end() && uf.data[conn.first].starter == -1) {
//                    pq.push(Edge(b, conn.first, conn.second));
//                }
//            }
//            // function
//            ++connectionsMade;
//        }
//    }
    cout << total + (n - s) * l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0;i < n; ++i) {
        solve();
    }
    return 0;
}

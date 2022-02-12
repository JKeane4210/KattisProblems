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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    if (n == 2 && k == 1) {
        cout << "impossible" << endl;
        return 0;
    }
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
        if ((a == 0 && b == n - 1) || (a == n - 1 && b == 0)) {
            int order[n];
            for (int j = 0; j < n; ++j) {
                order[j] = 0;
            }
            int ind = 0;
            if (k >= 2) {
                ind += 2;
                order[a] = 'N';
                order[b] = 'N';
            } else {
                order[a] = 'S';
                order[b] = 'S';
            }
            for (int j = 0; j < n; ++j) {
                if (order[j] == 0) {
                    order[j] = ind < k ? 'N' : 'S';
                    ++ind;
                }
            }
//            cout << "*" << ind << endl;
            for (char c: order) {
                cout << c;
            }
            cout << endl;
            return 0;
        }
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
    // Creating DAG
    graph D(n);
    set<pii> conns;
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
                D[prev].pb(front);
                q.push(prev);
            }
        }
    }
    // create a topological sort
    set<int> processed;
    vector<int> top_sort;
    stack<int> dfs;
    dfs.push(0);
    while (!dfs.empty()) {
        int top = dfs.top();
        bool successors_visited = true;
        for (int successor: D[top]) {
            if (processed.find(successor) == processed.end()) {
                successors_visited = false;
                dfs.push(successor);
            }
        }
        if (successors_visited) {
            dfs.pop();
            top_sort.pb(top);
            processed.insert(top);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    char order[n];
    for (int i = 0; i < n; ++i) {
        order[i] = 0;
    }
    int ind = 0;
    for (int i: top_sort) {
        order[i] = ind < k ? 'N' : 'S';
        ++ind;
    }
    for (int i = 0; i < n; ++i) {
        if (order[i] == 0) {
            order[i] = ind < k ? 'N' : 'S';
            ++ind;
        }
    }
    for (char c: order) {
        cout << c;
    }
    cout << endl;

    return 0;
}
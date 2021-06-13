//
// Created by Jonny Keane on 6/7/21.
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


class DijstrasStep {
public:
    DijstrasStep(int a, int b, unsigned long long totalDist) : a(a), b(b), totalDist(totalDist) {};
    int a;
    int b;
    unsigned long long totalDist;
    friend bool operator<(const DijstrasStep& a, const DijstrasStep& b);
};

bool operator<(const DijstrasStep& a, const DijstrasStep& b) {
    return a.totalDist > b.totalDist;
}

bool onPathOfOtherVisited(const set<int>& toVisit, const int * predecessors, int node) {
    while (node != 0) {
        if (toVisit.count(node) != 0) {
            return true;
        }
        node = predecessors[node];
    }
    return false;
}

// priority queue for the ones that don't add steps and priority queue that adds a branch from current??
int main() {
    int N, M, C;
    cin >> N >> M >> C;
    vector<pair<int, int>> graph[N];
    set<int> toVisit;
    for (int i = 0; i < C; ++i) {
        int person;
        cin >> person;
        toVisit.insert(person);
    }
    for (int i = 0; i < M; i++) {
        int nodeA, nodeB, weight;
        cin >> nodeA >> nodeB >> weight;
        graph[nodeA].emplace_back(nodeB, weight); //only one add because it is directional
    }
    unsigned long long tableOfPaths[N];
    int predecessors[N];
    for (int i = 0; i < N; i++) tableOfPaths[i] = ~0;
//    for (int i = 0; i < N; i++) predecessors[i] = 0;
    priority_queue<DijstrasStep> pq;
    pq.push(DijstrasStep(0, 0, 0));
    //MAIN LOOP
    while (!pq.empty()) {
        DijstrasStep shortest = pq.top();
        pq.pop();
        if (shortest.totalDist > tableOfPaths[shortest.b]) {
            continue;
        }
        // if equals and leaves contains new one
        if (shortest.totalDist < tableOfPaths[shortest.b] ||
                (shortest.totalDist == tableOfPaths[shortest.b] && onPathOfOtherVisited(toVisit, predecessors, shortest.a))) {
            predecessors[shortest.b] = shortest.a;
            for (const auto &p: graph[shortest.b]) {
                pq.push(DijstrasStep(shortest.b, p.first, shortest.totalDist + p.second));
            }
            tableOfPaths[shortest.b] = shortest.totalDist;
        }
    }
    // see how many nodes are a part of this
    set<int> visited;
    for (int val: toVisit) {
        int pred = val;
        visited.insert(val);
        while (pred != 0) {
            pred = predecessors[pred];
            visited.insert(pred);
        }
    }
    int res = 1; // you know you have at least one
     // see how many branch
    set<int> nodes;
    for (int val: visited) {
        if (val == 0) continue;
        if (nodes.count(predecessors[val]) != 0) {
            ++res;
        } else {
            nodes.insert(predecessors[val]);
        }
    }
    cout << res << endl;
    return 0;
}
// 0 -> 1
// 0 -> 3
// 1 -> 2
// 3 -> 2
// but you are not looking for 1

//4 4 2
//2 3
//0 1 1
//0 3 1
//3 2 1
//1 2 1

// should be 1


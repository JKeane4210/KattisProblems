//
// Created by Jonny Keane on 7/17/21.
//

#include <bits/stdc++.h>

#define ll long long

#define pii pair<int, int>
#define pll pair<ll,ll>

using namespace std;

class DijkstrasStep {
public:
    int from;
    int to;
    int sumTime;
    int sumMoney;
    int V;

    /// Initializes node ID and total distance
    /// \param nodeID Node ID
    /// \param totalDist Total distance
    DijkstrasStep(int from, int to, int sumTime, int sumMoney) : from(from), to(to), sumTime(sumTime), sumMoney(sumMoney), V(sumTime * sumMoney) {};

    /// Comparator of DijkstrasSteps for use in priority queue
    /// \param a A step
    /// \param b Another step
    /// \return If a is "lesser"
    /// \tparam The type of the weight (int/double)
    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.V > b.V;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, int>>> conns[N];
    for (int i = 0; i < N; ++i) {
        conns[i] = vector<pair<int, pair<int, int>>>();
    }
    for (int i = 0; i < M; ++i) {
        int x, y, t, c;
        cin >> x >> y >> t >> c;
        conns[x].emplace_back(y, make_pair(t, c));
        conns[y].emplace_back(x, make_pair(t, c));
    }

    int parents[N];
    pair<int, int> shortestPaths[N];
    for (int i = 0; i < N; ++i) {
        shortestPaths[i] = make_pair(INT_MAX, 1);
    }
    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(0, 0, 0, 0));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (shortestPaths[top.to].first * shortestPaths[top.to].second <= top.V) continue;
        parents[top.to] = top.from;
        shortestPaths[top.to] = make_pair(top.sumTime, top.sumMoney);
        for (auto conn: conns[top.to]) {
            pq.push(DijkstrasStep(top.to, conn.first, conn.second.first + top.sumTime, conn.second.second + top.sumMoney));
        }
    }
    pair<int, int> max = {0, 0};
    set<int> visited;
    vector<pair<int, int>> finalTree;
    for (int i = 0; i < N; ++i) {
        if (shortestPaths[i].first * shortestPaths[i].second > max.first * max.second) {
            max = shortestPaths[i];
        }
        int curr = i;
        while (visited.count(curr) == 0) {
            visited.insert(curr);
            int parent = parents[curr];
            if (curr != parent) {
                finalTree.emplace_back(parent, curr);
            }
            curr = parent;
        }
    }
    cout << max.first << " " << max.second << endl;
    for (auto conn: finalTree) {
        cout << conn.first << " " << conn.second << endl;
    }

    return 0;
}
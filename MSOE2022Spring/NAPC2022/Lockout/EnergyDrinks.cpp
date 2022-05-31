//
// Created by keanej on 5/28/2022.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>
#define wgraph V<V<pii>>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int x2, y2;

class DijkstrasStep {
public:
    pii nodeID;
    int totalDist;
    int jump_size;

    DijkstrasStep(pii nodeID, int totalDist, int jump_size) : nodeID(nodeID), totalDist(totalDist), jump_size(jump_size) {}

    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        if (a.totalDist == b.totalDist) {
            if (a.jump_size == b.jump_size) {
                return abs(a.nodeID.first - x2) + abs(a.nodeID.second - y2) > abs(b.nodeID.first - x2) + abs(b.nodeID.second - y2);
            }
            return a.jump_size < b.jump_size;
        }
        return a.totalDist > b.totalDist;
    }
};


int deltas[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    string grid[n];
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int x1, y1;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;

    int shortest[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            shortest[i][j] = INT_MAX;
        }
    }

    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(mp(x1, y1), 0, 0));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        if (top.totalDist >= shortest[top.nodeID.first][top.nodeID.second]) continue;
        shortest[top.nodeID.first][top.nodeID.second] = top.totalDist;
        if (top.nodeID == mp(x2, y2)) {
            break;
        }
        for (auto delta: deltas) {
            for (int i = 1; i <= k; ++i) {
                int nx = delta[0] * i + top.nodeID.first;
                int ny = delta[1] * i + top.nodeID.second;
                if (nx < 0 || nx >= n) break;
                if (ny < 0 || ny >= m) break;
                if (grid[nx][ny] == '#') break;
//                cout << nx << " " << ny << endl;
                if (top.totalDist + 1 < shortest[nx][ny]) {
                    pq.push(DijkstrasStep(mp(nx, ny), top.totalDist + 1, i));
                }
            }
        }
    }

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << shortest[i][j] << " ";
//        }
//        cout << endl;
//    }

    if (shortest[x2][y2] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << shortest[x2][y2] << endl;
    }


    return 0;
}
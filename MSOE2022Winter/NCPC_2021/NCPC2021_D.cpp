//
// Created by Jonny Keane on 2/9/22.
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

int deltas[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char dirs[4] = {'S', 'E', 'N', 'W'};

class DijkstrasStep {
public:
    pii nodeID;
    int totalDist;

    DijkstrasStep(pii nodeID, int totalDist) : nodeID(nodeID), totalDist(totalDist) {};

    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    cin >> w >> h;
    vector<string> grid(h);
    set<pii> locs;
    int shortestPaths[h][w];
    pii start;
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == 'S') {
                start = make_pair(i, j);
                locs.insert(start);
            }
            shortestPaths[i][j] = INT_MAX;
        }
    }
    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(start, 0));
    //MAIN LOOP
    while (!pq.empty()) {
        DijkstrasStep shortest = pq.top();
        pq.pop();
        if (shortest.totalDist >= shortestPaths[shortest.nodeID.first][shortest.nodeID.second]) {
            continue;
        }
        shortestPaths[shortest.nodeID.first][shortest.nodeID.second] = shortest.totalDist;
        for (auto delta: deltas) {
            int nr = shortest.nodeID.first + delta[0];
            int nc = shortest.nodeID.second + delta[1];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] != '#') {
                pq.push(DijkstrasStep(make_pair(nr, nc), shortest.totalDist + 1));
            }
        }
    }

    string moves;
    cin >> moves;
    int dist = 1;
    for (char c: moves) {
        set<pii> new_locs;
        for (auto loc: locs) {
//            cout << loc.first <<  " " << loc.second << endl;
            for (int i = 0; i < 4; ++i) {
                if (dirs[i] != c) {
//                    cout << dirs[i] << " " << loc.first + deltas[i][0] << " " << loc.second + deltas[i][1] << endl;
                    int nr = loc.first + deltas[i][0];
                    int nc = loc.second + deltas[i][1];
//                    cout << shortestPaths[nr][nc] << endl;
                    if (nr >= 0 && nr < h && nc >= 0 && nc < w && grid[nr][nc] != '#' && shortestPaths[nr][nc] == dist) {
                        new_locs.insert(make_pair(nr, nc));
                    }
                }
            }
        }
        locs = new_locs;
        ++dist;
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#' || locs.find(make_pair(i, j)) == locs.end()) {
                cout << grid[i][j];
            } else {
                cout << '!';
            }
        }
        cout << endl;
    }

    return 0;
}
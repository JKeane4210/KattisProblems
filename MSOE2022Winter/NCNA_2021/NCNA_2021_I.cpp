//

// Created by event on 2/26/2022.
//

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

#define mp make_pair
#define pii pair<int, int>

class DijkstrasStep {
public:
    pii nodeId;
    double totalDist;

    DijkstrasStep(pii nodeId, double totalDist) : nodeId(nodeId), totalDist(totalDist) {}

    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

double distance(pii p1, pii p2) {
    return sqrt((p1.second - p2.second) * (p1.second - p2.second) + (p1.first - p2.first) * (p1.first - p2.first));
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool can_cross(int r1, int c1, int r2, int c2, vector<string> grid) {
    if (gcd(r2 - r1, c2 - c1) != 1) return false;
    if (r1 == r2 || c1 == c2) {
        return true;
    }
    double curr_r = r1;
    for (int i = c1 + 1; i <= c2; ++i) {
        double next_r = curr_r + (double)(r2 - r1) / (c2 - c1);
        int check_blocks = (int)next_r + 1; // get the number of blocks that need to be checked
        if (i == c2) {
            check_blocks = r2;
        }
//        if (r1 != r2 && c1 != c2) {
//            cout << (int) curr_r + 1 << "-" << check_blocks << endl;
//        }
        for (int j = (int)curr_r + 1; j <= check_blocks; ++j) {
            if (grid[j - 1][i - 1] == '#') {
//                cout << "*" << r1 << " " << c1 << " -> " << r2 << " " << c2 << endl;
                return false;
            }
        }
        curr_r = next_r;
    }
    return true;
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    set<pii> points;
    points.insert(mp(0, 0));
    points.insert(mp(r, c));
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
//        for (int j = 0; j < c; ++j) {
//            if (grid[i][j] == '#') {
//                points.insert(mp(i, j));
//                points.insert(mp(i, j + 1));
//                points.insert(mp(i + 1, j));
//                points.insert(mp(i + 1, j + 1));
//            }
//        }
    }
    for (int i = 0; i <= r; ++i) {
        for (int j = 0; j <= c; ++j) {
            points.insert(mp(i, j));
        }
    }
//    if (points.size() == 2) {
//        cout << distance(mp(r, c), mp(0, 0)) << endl;
//        return 0;
//    }
    map<pii, vector<pii>> conns;
    map<pii, double> shortestPathTable;
    for (auto p: points) {
        shortestPathTable[p] = INFINITY;
        conns[p] = vector<pii>();
    }
    for (auto p1: points) {
        for (auto p2: points) {
            if (p1 == p2) continue;
            if (p1.first <= p2.first && p1.second <= p2.second) {
                if (can_cross(p1.first, p1.second, p2.first, p2.second, grid)) {
//                    if (p1.first != p2.first && p1.second != p2.second) {
//                        cout << p1.first << " " << p1.second << " -> " << p2.first << " " << p2.second << endl;
//                    }
                    conns[p1].emplace_back(p2);
                }
            }
        }
    }

    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(mp(0, 0), 0));
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (top.totalDist >= shortestPathTable[top.nodeId]) {
            continue;
        }
//        cout << top.nodeId.first
        shortestPathTable[top.nodeId] = top.totalDist;
        for (const auto & p: conns[top.nodeId]) {
            pq.push(DijkstrasStep(p, top.totalDist + distance(p, top.nodeId)));
        }
    }
    cout.precision(10);
    cout << shortestPathTable[mp(r, c)] << endl;

    return 0;
}
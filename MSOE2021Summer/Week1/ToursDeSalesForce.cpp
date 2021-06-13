//
// Created by Jonny Keane on 5/26/21.
//

#include <bits/stdc++.h>

using namespace std;

float dst(pair<float, float> p1, pair<float, float> p2) {
    return sqrt((p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second));
}

struct TourMerge {
    public:
        int keptTour;
        int firedTour;
        float distance;
        TourMerge(int tA, int tB, float d) {
            keptTour = tA;
            firedTour = tB;
            distance = d;
        }
    friend bool operator<(const TourMerge& a, const TourMerge& b);
};

bool operator<(const TourMerge& a, const TourMerge& b) {
    return a.distance > b.distance;
}

// array for dynamic programming [n - 1][2 ^ (n - 1)] (removing your initial point)
// minimum wait/max matching
    // minimum cost/max flow
    // hungarian algorithm

float memo[16][1 << 16];

// backtracking combinations
void combinations(int set, int at, int r, int N, vector<int>* subsets) {
    if (r == 0) {
        subsets->push_back(set);
    } else {
        for (int i = at; i < N; ++i) {
            set |= (1 << i);
            combinations(set, i + 1, r - 1, N, subsets);
            set &= ~(1 << i);
        }
    }
}

vector<int> combinations(int r, int N) {
    vector<int> subsets;
    combinations(0, 0, r, N, &subsets);
    return subsets;
}

bool notIn(int i, int subset) {
    return ((1 << i) & subset) == 0;
}

float findSalesTour(vector<pair<float, float>> tour) {
    const float INF = 100000000.0;
    const int N = tour.size();
    const int S = 0;
    float distances[tour.size()][tour.size()];
    for (int i = 0; i < tour.size(); ++i) {
        for (int j = 0; j < tour.size(); ++j) {
            distances[i][j] = i == j ? 0 : dst(tour[i], tour[j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < (1<<N); ++j) {
            memo[i][j] = INF;
        }
    }
    // setup
    for (int i = 0; i < N; ++i) { // save the distances into memory for optimal node (a->b)
        if (i == S) continue;
        memo[i][(1 << S) | (1 << i)] = distances[S][i];
    }
    // solve
    for (int r = 3; r <= N; ++r) { // the number of nodes in a partial tour
        for (int subset: combinations(r, N)) {
//            cout << subset << endl;
            if (notIn(S, subset)) continue; // have to contain S
            for (int next = 0; next < N; ++next) { // checking which nodes to go to
                if (next == S || notIn(next, subset)) continue; // can't go back to self or to something not in the subset
                int state = subset ^ (1 << next);
                float minDist = INF;
                for (int e = 0; e < N; ++e) { // end nodes to check which optimizes partial tour
                    if (e == S || e == next || notIn(e, subset)) continue;
                    float newDistance = memo[e][state] + distances[e][next];
                    if (newDistance < minDist) {
                        minDist = newDistance;
                    }
                }
                memo[next][subset] = minDist; // store best partial tour in table
            }
        }
    }
    // findMinCost
    const int END_STATE = (1 << N) - 1;
    float minTourCost = INF;
    for (int e = 0; e < N; ++e) {
        if (e == S) continue;
        float tourCost = memo[e][END_STATE] + distances[e][S];
        if (tourCost < minTourCost) {
            minTourCost = tourCost;
        }
    }
    return minTourCost;
// My Way of DP Exceeds Memory
//    vector<pair<float, pair<int, int>>> solutions[tour.size()];
//    vector<pair<float, pair<int, int>>> layer1;
//    layer1.emplace_back(0, make_pair(0, 1)); // distance, last node and visited
//    solutions[0] = layer1;
//    for (int i = 0; i < tour.size() - 1; ++i) {
//        vector<pair<float, pair<int, int>>> layerN;
//        for (auto path: solutions[i]) {
//            for (int j = 0; j < tour.size(); ++j) {
//                if (j != path.second.first && (path.second.second & (1 << j)) == 0) {
//                    layerN.emplace_back(path.first + distances[path.second.first][j], make_pair(j, path.second.second | (1 << j)));
//                }
//            }
//        }
//        solutions[i + 1] = layerN;
//    }
//    float min = INF;
//    for (auto path: solutions[tour.size() - 1]) {
//        if (path.first + distances[path.second.first][0] < min) {
//            min = path.first + distances[path.second.first][0];
//        }
//    }
//    return min;
}

float findSalesTour(vector<pair<float, float>> tA, const vector<pair<float, float>>& tB) {
    vector<pair<float, float>> tour(std::move(tA));
    for (auto v: tB) {
        tour.push_back(v);
    }
    return findSalesTour(tour);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d;
    cin >> d;
    float initialDistance = 0;
    vector<pair<float, float>> tours[d/2];
    vector<pair<float, float>> firedTours[d/2];
    for (int i = 0; i < d; ++i) {
        int n;
        cin >> n;
        vector<pair<float, float>> tour(n);
        for (int j = 0; j < n; ++j) { // first d/2 are
            float x, y;
            cin >> x >> y;
            tour[j] = make_pair(x, y);
        }
        initialDistance += findSalesTour(tour);
        if (i < d/2) {
            firedTours[i] = tour;
        } else {
            tours[i - d/2] = tour;
        }
    }
    float totalDistance = 0;
    int toursVisited = 0;
    int firedToursVisited = 0;
    int matches = 0;
    priority_queue<TourMerge> pq;
    for (int i = 0; i < d/2; ++i) {
        for (int j = 0; j < d/2; ++j) {
            TourMerge tourMerge(i, j, findSalesTour(tours[i], firedTours[j]));
            pq.push(tourMerge);
        }
    }
    while (matches < d/2) {
        TourMerge top = pq.top();
        pq.pop();
        if ((toursVisited & (1 << top.keptTour)) == 0 && (firedToursVisited & (1 << top.firedTour)) == 0) {
            toursVisited |= 1 << top.keptTour;
            firedToursVisited |= 1 << top.firedTour;
            totalDistance += top.distance;
            ++matches;
        }
    }
    printf("%5f %5f", initialDistance, totalDistance);
    return 0;
}

// O(n!) way of doing it:
//float res = recursiveTour(tour, 0, 0, 0, 0);
//float recursiveTour(vector<pair<float, float>> tour, int first, int curr, float dist, int visited) {
//    visited |= (1 << curr);
//    float min_ = -1;
//    for (int i = 0; i < tour.size(); ++i) {
//        if ((visited & (1 << i)) == 0) {
//            float path = recursiveTour(tour, first, i, dist + dst(tour[curr], tour[i]), visited);
//            if (min_ == -1 || path < min_) {
//                min_ = path;
//            }
//        }
//    }
//    if (min_ == -1) {
//        return dist + dst(tour[curr], tour[first]);
//    } else {
//        return min_;
//    }
//}
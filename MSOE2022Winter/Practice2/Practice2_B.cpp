//
// Created by Jonny Keane on 2/5/22.
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
#define w_graph V<vpii>

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
    int totalDist;

    DijkstrasStep(int nodeID, int totalDist) : nodeID(nodeID), totalDist(totalDist) {};

    friend bool operator<(const DijkstrasStep &a, const DijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

class DayDijkstrasStep {
public:
    int nodeID;
    int totalDist;
    int hour;

    DayDijkstrasStep(int nodeID, int totalDist, int hour) : nodeID(nodeID), totalDist(totalDist), hour(hour) {};

    friend bool operator<(const DayDijkstrasStep &a, const DayDijkstrasStep &b) {
        return a.totalDist > b.totalDist;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    w_graph G(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].pb(mp(b, w));
        G[b].pb(mp(a, w));
    }


    int knightTable[n];
    for (int i = 0; i < n; ++i) {
        knightTable[i] = INT_MAX;
    }

    priority_queue<DijkstrasStep> pq;
    pq.push(DijkstrasStep(0, 0));
    //MAIN LOOP
    while (!pq.empty()) {
        DijkstrasStep shortest = pq.top();
        pq.pop();
        if (shortest.totalDist >= knightTable[shortest.nodeID]) {
            continue;
        }
        knightTable[shortest.nodeID] = shortest.totalDist;
        for (const auto& p: G[shortest.nodeID]) {
            pq.push(DijkstrasStep(p.first, shortest.totalDist + p.second));
        }
    }

    int dayTable[n][13];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 13; ++j) {
            dayTable[i][j] = INT_MAX;
        }
    }

    priority_queue<DayDijkstrasStep> pq2;
    pq2.push(DayDijkstrasStep(0, 0, 0));
    //MAIN LOOP
    while (!pq2.empty()) {
        DayDijkstrasStep shortest = pq2.top();
        pq2.pop();
        if (shortest.totalDist >= dayTable[shortest.nodeID][shortest.hour]) {
            continue;
        }
        dayTable[shortest.nodeID][shortest.hour] = shortest.totalDist;
        for (const auto& p: G[shortest.nodeID]) {
            if (12 - shortest.hour - p.second >= 0) {
                pq2.push(DayDijkstrasStep(p.first, shortest.totalDist + (24 - shortest.hour), 0)); // go to bed here
                pq2.push(DayDijkstrasStep(p.first, shortest.totalDist + p.second,
                                          shortest.hour + p.second)); // try to keep going
            }
        }
    }

    int min_day = INT_MAX;
    for (int i = 0; i < 13; ++i) {
        min_day = min(min_day, dayTable[n - 1][i]);
    }
    int min_knight = (knightTable[n - 1] - 1) / 12 * 24 + knightTable[n - 1] % 12;
    if (knightTable[n - 1] % 12 == 0 && knightTable[n - 1] != 0) {
        min_knight += 12;
    }
//    cout << "Knight " << min_knight << endl;
//    cout << "Day " << min_day << endl;
    cout << min_day - min_knight << endl;

    return 0;
}

/*
4 3
0 1 4
1 2 9
2 3 11
 */
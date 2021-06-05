//
// Created by Jonny Keane on 5/31/21.
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

class DijstrasStep {
public:
    DijstrasStep(int week, int seats, int firstWeek, int totalDist) :
        week(week), seats(seats), firstWeek(firstWeek), totalDist(totalDist) {};
    int week;
    int firstWeek;
    int seats;
    int totalDist;
    friend bool operator<(const DijstrasStep& a, const DijstrasStep& b);
};

bool operator<(const DijstrasStep& a, const DijstrasStep& b) {
    return a.totalDist < b.totalDist;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> weeks[W + 1];
    for (int i = 0; i < W + 1; ++i) {
        int K;
        cin >> K;
        vector<pair<int, int> > week(K);
        for (int j = 0; j < K; ++j) {
            int cost;
            cin >> cost;
            week[j] = make_pair(cost, 0);
        }
        for (int j = 0; j < K; ++j) {
            int seats;
            cin >> seats;
            week[j].second = seats;
        }
        weeks[i] = week;
    }
    priority_queue<DijstrasStep> pq;
    for (auto p: weeks[0]) {
        pq.push(DijstrasStep(0, N - p.second, p.first, p.second * p.first));
    }
    pair<int, int> res = {0, 0};
    //MAIN LOOP
    int iters = 0;
    while (!pq.empty()) {
        ++iters;
        DijstrasStep max = pq.top();
        pq.pop();
        if (max.seats == 0 || max.week == W) {
            if (max.totalDist >= res.first) {
                res.first = max.totalDist;
                if (max.totalDist == res.first) {
                    res.second = min(res.first, max.firstWeek);
                } else {
                    res.second = max.firstWeek;
                }
            }
            continue;
        }
        for (auto p: weeks[max.week + 1]) {
            if (max.seats <= p.second) {
                pq.push(DijstrasStep(max.week + 1, 0, max.firstWeek, max.totalDist + p.first * max.seats));
            } else {
                pq.push(DijstrasStep(max.week + 1, max.seats - p.second, max.firstWeek,
                                     max.totalDist + p.first * p.second));
            }
        }
    }
    cout << iters << endl;
    cout << res.first << endl;
    cout << res.second << endl;
}
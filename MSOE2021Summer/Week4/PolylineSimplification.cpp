//
// Created by Jonny Keane on 6/13/21.
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
#define minimum(a) *min_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

struct Point {
public:
    int ind;
    int x, y;
    Point *prev;
    Point *next;
    int area = INT_MAX;
    Point(int x, int y, int ind) : x(x), y(y), ind(ind), prev(nullptr), next(nullptr) {}

    void calculateArea() {
        if (prev != nullptr && next != nullptr) {
            area = abs(prev->x*(y - next->y) + x*(next->y - prev->y) + next->x*(prev->y - y));
        }
    }
};
struct Compare {
    bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if (a.first == b.first) {
            return a.second.first > b.second.first;
        }
        return a.first > b.first;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    Point* points[n + 1]; // everything pointing to same place
    for (int i = 0; i < n + 1; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = new Point(x, y, i);
    }
    // <area <ind, round>>
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> pq;
    points[0]->next = points[1];
    for (int i = 1; i < n; ++i) {
        points[i]->prev = points[i - 1];
        points[i]->next = points[i + 1];
        points[i]->calculateArea();
        pq.push(make_pair(points[i]->area, make_pair(i, 0)));
    }
    points[n]->prev = points[n - 1];
    int round = 0;
    int currentRounds[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        currentRounds[i] = 0;
    }
    while (round < n - m) {
        auto top = pq.top();
        pq.pop();
        if (top.second.second < currentRounds[top.second.first]) continue;
        ++round;
        cout << top.second.first << endl;
        Point* minPt = points[top.second.first];
        Point* minPrev = minPt->prev;
        Point* minNext = minPt->next;
        minPrev->next = minPt->next;
        minNext->prev = minPt->prev;
        minPrev->calculateArea();
        minNext->calculateArea();
        currentRounds[minPrev->ind] = round;
        currentRounds[minNext->ind] = round;
        pq.push(make_pair(minPrev->area, make_pair(minPrev->ind, round)));
        pq.push(make_pair(minNext->area, make_pair(minNext->ind, round)));
    }

    return 0;
}
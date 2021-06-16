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
    long double area = HUGE_VALL;
    Point(int x, int y, int ind) : x(x), y(y), ind(ind), prev(nullptr), next(nullptr) {}

    void calculateArea() {
        if (prev != nullptr && next != nullptr) {
            long double s1 = sqrt((x - prev->x)*(x - prev->x) + (y - prev->y)*(y - prev->y));
            long double s2 = sqrt((next->x - x)*(next->x - x) + (next->y - y)*(next->y - y));
            long double s3 = sqrt((next->x - prev->x)*(next->x - prev->x) + (next->y - prev->y)*(next->y - prev->y));
            long double p = (s1 + s2 + s3) / 2.0;
            area = sqrt(p * (p - s1) * (p - s2) * (p - s3)); // Heron's Formula
        }
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
    points[0]->next = points[1];
    for (int i = 1; i < n; ++i) {
        points[i]->prev = points[i - 1];
        points[i]->next = points[i + 1];
        points[i]->calculateArea();
    }
    points[n]->prev = points[n - 1];

    for (int i = 0; i < n - m; ++i) {
        long double min = HUGE_VALL;
        Point* minPt = points[0];
        Point* curr = points[0];
        while (curr != nullptr) {
            if (curr->area < min) {
                min = curr->area;
                minPt = curr;
            }
            curr = curr->next;
        }
        cout << minPt->ind << endl;
        Point* minPrev = minPt->prev;
        Point* minNext = minPt->next;
        minPrev->next = minPt->next;
        minNext->prev = minPt->prev;
        minPrev->calculateArea();
        minNext->calculateArea();
    }

    return 0;
}
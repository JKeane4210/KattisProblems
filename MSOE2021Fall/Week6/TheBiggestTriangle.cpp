//
// Created by Jonny Keane on 10/13/21.
//

// y2 - y1 / x2 - x1 = m
// y - y1 = m(x - x1)
// ma(x - x1a) + y1a = mb(x - x1b) + y1b
// (ma - mb)(x) = ma*x1a - y1a - mb*x1b + y1b
// x = (max1a - y1a - mbx1b + y1b)/(ma - mb)
// y = m(x - x1) + y1

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

bool isParallel(int x1a, int y1a, int x2a, int y2a,
                int x1b, int y1b, int x2b, int y2b)  {
    double ma = 1.0 * (y2a - y1a) / (x2a - x1a);
    double mb = 1.0 * (y2b - y1b) / (x2b - x1b);
    return ma == mb;
}

pair<double, double> intersect(int x1a, int y1a, int x2a, int y2a,
                         int x1b, int y1b, int x2b, int y2b) {
    if (x1a == x2a) {
        double x = 1.0 * x1a;
        double mb = 1.0 * (y2b - y1b) / (x2b - x1b);
        double y = mb * (x - x1b) + y1b;
        return make_pair(x, y);
    } else if (x1b == x2b) {
        double x = 1.0 * x1b;
        double ma = 1.0 * (y2a - y1a) / (x2a - x1a);
        double y = ma * (x - x1a) + y1a;
        return make_pair(x, y);
    } else {
        double ma = 1.0 * (y2a - y1a) / (x2a - x1a);
        double mb = 1.0 * (y2b - y1b) / (x2b - x1b);
        double x = 1.0 * ((long)(y2a - y1a) * (x2b - x1b) * x1a +
                        (long)(y1b - y1a) * (x2b - x1b) * (x2a - x1a) -
                        (long)(y2b - y1b) * (x2a - x1a) * x1b) /
                        ((long)(y2a - y1a) * (x2b - x1b) - (y2b - y1b) * (x2a - x1a));
        double y = ma * (x - x1a) + y1a;
        return make_pair(x, y);
    }
}

double distance(pair<double, double> p1, pair<double, double> p2) {
    return sqrt(pow(p2.second - p1.second, 2) + pow(p2.first - p1.first, 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int lines[n][4];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> lines[i][j];
        }
    }

    double max_perimeter = -1;
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (isParallel(lines[i][0], lines[i][1], lines[i][2], lines[i][3],
                               lines[j][0], lines[j][1], lines[j][2], lines[j][3]) ||
                   isParallel(lines[k][0], lines[k][1], lines[k][2], lines[k][3],
                               lines[j][0], lines[j][1], lines[j][2], lines[j][3]) ||
                   isParallel(lines[i][0], lines[i][1], lines[i][2], lines[i][3],
                              lines[k][0], lines[k][1], lines[k][2], lines[k][3])) {
                    continue;
                }
                pair<double, double> p1 = intersect(lines[i][0], lines[i][1], lines[i][2], lines[i][3],
                                   lines[j][0], lines[j][1], lines[j][2], lines[j][3]);
                pair<double, double> p2 = intersect(lines[k][0], lines[k][1], lines[k][2], lines[k][3],
                                   lines[j][0], lines[j][1], lines[j][2], lines[j][3]);
                pair<double, double> p3 = intersect(lines[i][0], lines[i][1], lines[i][2], lines[i][3],
                                   lines[k][0], lines[k][1], lines[k][2], lines[k][3]);
                double s1 = distance(p1, p2);
                double s2 = distance(p1, p3);
                double s3 = distance(p2, p3);
                if (s1 + s2 > s3 && s2 + s3 > s1 && s1 + s3 > s2) {
                    max_perimeter = max(max_perimeter, s1 + s2 + s3);
                }
            }
        }
    }
    if (max_perimeter == -1) {
        printf("no triangle\n");
    } else {
        printf("%.10f\n", max_perimeter);
    }

    return 0;
}
//
// Created by Jonny Keane on 6/1/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    double D, L;
    cin >> N >> D >> L;
    double V = L * 1000; // convert to cm^3
    pair<double, double> verts[N];
    int left = -1, right = -1;
    double max_ = 0;
    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;
        verts[i] = make_pair(x, y);
        max_ = max(max_, y);
        if (y == 0) {
            if (left == -1) {
                left = i;
            } else {
                right = i;
            }
        }
    }
    if (left == 0 && right == N - 1) {
        swap(left, right);
    }
    double totalHeight = 0;
    double lx1 = verts[left].first, rx1 = verts[right].first;
    while (verts[left].second != max_ || verts[right].second != max_) {
        pair<double, double> currLeft = verts[left], currRight = verts[right];
        pair<double, double> nextLeft = verts[(left - 1 + N) % N], nextRight = verts[(right + 1) % N];
        cout << totalHeight << " " << nextLeft.second << " " << nextRight.second << endl;
        double maxHeight;
        if (nextLeft.second < nextRight.second) {
            maxHeight = nextLeft.second;
            left = (left - 1 + N) % N;
        } else if (nextLeft.second == nextRight.second) {
            maxHeight = nextLeft.second;
            left = (left - 1 + N) % N;
            right = (right + 1) % N;
        } else {
            maxHeight = nextRight.second;
            right = (right + 1) % N;
        }
        double lSlope = ((nextLeft.second - currLeft.second) / (nextLeft.first - currLeft.first));
        double rSlope = ((nextRight.second - currRight.second) / (nextRight.first - currRight.first));
        double lx2 = lx1 + (maxHeight - totalHeight) / lSlope;
        double rx2 = rx1 + (maxHeight - totalHeight) / rSlope;
        double sectionV = D * (maxHeight - totalHeight) * (rx2 - lx2 + rx1 - lx1) / 2.0;
        if (V > sectionV) {
            V -= sectionV;
            totalHeight = maxHeight;
            lx1 = lx2;
            rx1 = rx2;
        } else {
            double a = (lSlope - rSlope) / (rSlope * lSlope);
            double finalHeight;
            if ((lSlope == INFINITY || -lSlope == INFINITY) && (rSlope == INFINITY || -rSlope == INFINITY) ) {
                finalHeight = V / (D * (rx1 - lx1));
                printf("%.2f\n", totalHeight + finalHeight);
                return 0;
            } else if (lSlope == INFINITY || -lSlope == INFINITY) {
                a = 1 / rSlope;
            } else if (rSlope == INFINITY || -rSlope == INFINITY) {
                a = -1 / lSlope;
            }
            double b = 2 * (rx1 - lx1);
            double c = -2.0 * V / D;
            finalHeight = (-b + sqrt(b*b - 4*a*c)) / (2*a); // need the max of it?
//            cout << finalHeight << endl;
            printf("%.2f\n", totalHeight + finalHeight);
            return 0;
        }
    }
    printf("%.2f\n", totalHeight);
    return 0;
}

//6
//30 30
//10 0
//30 0
//40 20
//30 40
//10 40
//0 20





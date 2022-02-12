//
// Created by Jonny Keane on 2/8/22.
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

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(1.0 * ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x10, y10, x20, y20, x1f, y1f, x2f, y2f;
    cin >> x10 >> y10 >> x20 >> y20 >> x1f >> y1f >> x2f >> y2f;
    double d1 = dist(x10, y10, x20, y20);
    double d2 = dist(x1f, y1f, x2f, y2f);
    double res = max(d1, d2);
    cout.precision(10);
    cout << res << endl;

    return 0;
}
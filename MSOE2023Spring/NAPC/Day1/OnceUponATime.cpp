//
// Created by keanej on 5/26/2023.
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
#define wgraph V<V<pii>>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a; }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b); return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line;
    int n = -1, m, a, k;
    while (n != 0) {
        getline(cin, line);
        stringstream ss(line);
        ss >> n >> m >> a >> k; // m is a, a is b
        if (n == 0 && m == 0 && a == 0 && k == 0) break;
        int x, y, g;
        if (a > m) {
            g = gcd(a, m, y, x);
//            cout << x << " " << y << endl;
//            cout << x * m + n << endl;
        } else {
            g = gcd(m, a, x, y);
        }
        cout << x << " " << y << endl;
//        if ((g == a || g == m) && k != ) {
//
//        }
//        cout <<
        if ((g == a || g == m) && (k - n) % g != 0) {
            cout << "Impossible" << endl;
        } else {
            cout << x * (k - n) * m + n << endl;
        }
    }

    return 0;
}

//
// Created by Jonny Keane on 1/22/22.
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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

 g(long n) {
    long a = 0;
    for (long i = 2; i <= n; ++i) {
        if (gcd(n, i) != 1) {
            ++a;
        }
    }
    return (double)a / (double)n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 100000;
    int max_val = -1;
    double max = 0;
    for (int i = 2; i <= n; ++i) {
        double g_n = g(i);
        if (g_n > max) {
            max = g_n;
            max_val = i;
//            cout << max << " " << max_val << endl;
        }
    }

//    int g = gcd(a, n);
//
//    cout << a / g << "/" << n / g << endl;

    return 0;
}
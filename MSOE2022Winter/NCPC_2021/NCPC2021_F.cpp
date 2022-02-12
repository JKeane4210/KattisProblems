//
// Created by Jonny Keane on 2/9/22.
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

long nCr(int n, int r) {
    long res = 1;
    for (int i = n; i > max(r, n- r); --i) {
        res *= i;
    }
    for (int i = 1; i <= min(r, n - r); ++i) {
        res /= i;
    }
    return res;
}

long ncr(int n, int r) {
    long res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    for (int i = 1; i <= r; ++i) {
        res /= i;
    }
    for (int i = 1; i <= n - r; ++i) {
        res /= i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // geometric -> E(X) = 1/p
    int n, k;
    long double p;
    cin >> n >> k >> p;
    cout << nCr(n, k) << " " << nCr(n, k) << endl;
    long double success = (long double)nCr(n, k) * pow(p, (long double)k) * pow(1 - p, (long double)n - k);

    cout.precision(12);
    cout << 1.0 / success * n << endl;

    return 0;
}
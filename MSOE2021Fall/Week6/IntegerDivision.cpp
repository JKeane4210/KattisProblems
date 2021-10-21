//
// Created by Jonny Keane on 10/12/21.
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

long long nC2(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    int vals[n];
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }
    sort(vals, vals + n);
    long long total = 0;
    int prevInd = 0;
    int ind = 0;
    int currDiv = -1;
    while (ind != n) {
        if (vals[ind] / d != currDiv) {
            if (ind - prevInd >= 2) {
                total += nC2(ind - prevInd);
            }
            prevInd = ind;
            currDiv = vals[ind] / d;
        }
        ++ind;
    }
    if (ind - prevInd >= 2) {
        total += nC2(ind - prevInd);
    }
    cout << total << endl;
    return 0;
}

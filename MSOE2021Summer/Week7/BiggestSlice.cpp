//
// Created by Jonny Keane on 7/8/21.
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

const int SLICES = 1296000;

bitset<SLICES> pizza;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        pizza.reset();
        int r, n, theta, min, sec;
        cin >> r >> n >> theta >> min >> sec;
        int delta = 3600 * theta + 60 * min + sec;
        int next = 0;
        while (!pizza[next] && n != 0) {
            pizza[next] = true;
            next = (next + delta) % SLICES;
            --n;
        }
        int maxSlice = 0;
        int currSlice = 0;
        for (int j = 0; j < SLICES; ++j) {
            if (pizza[j]) {
                maxSlice = max(maxSlice, currSlice);
                currSlice = 0;
            }
            ++currSlice;
        }
        maxSlice = max(currSlice, maxSlice);
        double percent = (double)maxSlice/(double)SLICES;
        double res = M_PI * pow((double)r, 2) * percent;
        printf("%.6f\n", res);
    }

    return 0;
}
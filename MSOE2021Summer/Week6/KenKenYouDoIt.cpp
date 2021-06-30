//
// Created by Jonny Keane on 6/27/21.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, t;
    char op;
    cin >> n >> m >> t >> op;
//    switch (op) {
//        case '+':
//            break;
//        case '*':
//            // check 2 squares
//            break;
//        case '/':
//            break;
//        case '-':
//            // check 2 squares
//            break;
//    }
//    pair<int, int> blocks
    int *sumCounts = (int *) malloc(m * (t + 1) * sizeof(int));                    // for each block the sums created there
    memset(sumCounts, 0, m * (t + 1) * sizeof(int));                             // initialize to 0
    for (int i = 0; i < m - 1; ++i) {                                                   // every block
        for (int j = 1; j <= n; ++j) {                                                  // every number
            for (int k = 0; k <= t - j; ++k) {                                          // every sum count
                sumCounts[(i + 1) * (t + 1) + k + j] += sumCounts[i * (t + 1) + k];
            }
        }
    }
    return 0;
}
//
// Created by Jonny Keane on 9/6/21.
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

    int n, k;
    cin >> n >> k;
    int min_sum = 0;
    int max_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i < k) {
            int score;
            cin >> score;
            min_sum += score;
            max_sum += score;
        } else {
            min_sum += -3;
            max_sum += 3;
        }
    }
    printf("%.5f %.5f", 1.0 * min_sum / n, 1.0 * max_sum / n);

    return 0;
}
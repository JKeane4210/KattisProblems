//
// Created by Jonny Keane on 4/2/22.
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

void solve(int num) {
    cout << "Case #" << num << ":";
    int vals[3][4];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> vals[i][j];
        }
    }
    int GOAL = 1000000;
    int poss_sum = 0;
    int sum[4];
    for (int i = 0; i < 4; ++i) {
        int max_ = INT_MAX;
        for (int j = 0; j < 3; ++j) {
            max_ = min(max_, vals[j][i]);
        }
        poss_sum += max_;
        sum[i] = min(GOAL, i == 0 ? max_ : max_ + sum[i - 1]);
    }
    if (poss_sum < GOAL) {
        cout << " IMPOSSIBLE" << endl;
    } else {
//        int check = 0;
        for (int i = 0; i < 4; ++i) {
            cout << " " << (i == 0 ? sum[i] : sum[i] - sum[i - 1]);
//            check += (i == 0 ? sum[i] : sum[i] - sum[i - 1]);
        }
        cout << endl;
//        cout << check << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve(i + 1);
    }

    return 0;
}

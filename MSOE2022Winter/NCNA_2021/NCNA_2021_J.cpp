//
// Created by Jonny Keane on 3/1/22.
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

    int n;
    cin >> n;
    int vals[n];
    for (int j = 0; j < n; ++j) {
        int t_i, i;
        cin >> t_i >> i;
        vals[i - 1] = t_i;
    }
    int lag = 0;
    int time = 1;
    for (int i = 0; i < n; ++i) {
//        cout << vals[i] << " " << time << endl;
        lag += max(0, vals[i] - time);
        time = max(time + 1, vals[i] + 1);
    }
    cout << lag << endl;

    return 0;
}
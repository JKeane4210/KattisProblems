//
// Created by keanej on 2/4/2023.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int rungs[m];
    for (int i = 0; i < m; ++i) {
        cin >> rungs[i];
    }
    int res[n];
    for (int i = 0; i < n; ++i) {
        int curr = i + 1;
        for (int j = 0; j < m; ++j) {
            if (curr == rungs[j]) {
//                cout << rungs[j] << "->" << rungs[j] + 1 << endl;
                curr++;
            } else if (curr == rungs[j] + 1) {
//                cout << rungs[j] + 1 << "->" << rungs[j] << endl;
                curr--;
            }
        }
        res[curr - 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << endl;
    }

    return 0;
}
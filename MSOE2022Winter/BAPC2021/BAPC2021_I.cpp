//
// Created by Jonny Keane on 2/23/22.
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

    int n;
    cin >> n;
    int mins[n];
    for (int i = 0; i < n; ++i) {
        cin >> mins[i];
    }
    int min_computers = 1;
    map<int, int> solves;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val == - 1) continue;
        min_computers = max((int)ceil((double)mins[i] / val), min_computers);
        solves[val] += mins[i];
    }
    int needed = 0;
    for (auto solve: solves) {
//        cout << solve.first << " " << solve.second + needed << endl;
        min_computers = max((int)ceil((double)(solve.second + needed) / (solve.first)), min_computers);
        needed += solve.second;
    }
    cout << min_computers << endl;

    return 0;
}
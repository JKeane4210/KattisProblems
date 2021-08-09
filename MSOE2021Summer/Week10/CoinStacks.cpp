//
// Created by Jonny Keane on 7/27/21.
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
    priority_queue<pair<int, int>> indVals;
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        if (val != 0) {
            indVals.push(make_pair(val, i));
        }
    }

    vector<pair<int, int>> moves;
    while (indVals.size() >= 2) {
        auto a = indVals.top(); indVals.pop();
        auto b = indVals.top(); indVals.pop();
        moves.emplace_back(make_pair(a.second, b.second));
        --a.first;
        --b.first;
        if (a.first > 0) {
            indVals.push(a);
        }
        if (b.first > 0) {
            indVals.push(b);
        }
    }
    if (indVals.empty()) {
        cout << "yes" << endl;
        for (auto move: moves) {
            cout << move.first << " " << move.second << endl;
        }
    } else {
        cout << "no" << endl;
    }

    return 0;
}
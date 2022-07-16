//
// Created by Jonny Keane on 7/16/22.
//

#include <bits/stdc++.h>
#include <unordered_map>

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

    int N, Q;
    int all = 0;
    unordered_map<int, int> vals;
    cin >> N >> Q;
    for (int i = 0; i < Q; ++i) {
        string cmd;
        cin >> cmd;
        if (cmd == "SET") {
            int p, v;
            cin >> p >> v;
            vals[p] = v;
        }
        else if (cmd == "RESTART") {
            int v;
            cin >> v;
            vals.clear();
            all = v;
        }
        else if (cmd == "PRINT") {
            int p;
            cin >> p;
            if (vals.find(p) == vals.end()) {
                cout << all << endl;
            } else {
                cout << vals[p] << endl;
            }
        }
    }

    return 0;
}
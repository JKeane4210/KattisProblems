//
// Created by keanej on 2/24/2023.
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

int calc_leafs(int curr, int * leafs, const V<vi> & conns) {
    if (conns[curr].empty()) { leafs[curr] = 1; return 1; }
    int num_leaves = 0;
    for (auto child: conns[curr]) {
        num_leaves += calc_leafs(child, leafs, conns);
    }
    leafs[curr] = num_leaves;
    return leafs[curr];
}

void solve(int c) {
    int n;
    cin >> n;
    ll fun[n + 1];
    int * indeg = (int *)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; ++i) cin >> fun[i];
    int conn[n + 1];
    V<vi> conns(n + 1, vi());
    for (int i = 1; i <= n; ++i) {
        cin >> conn[i];
        indeg[conn[i]]++;
        conns[conn[i]].pb(i);
    }
    // simplify the tree, removing any chains of 1's
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] != 1) {
            int curr = conn[i];
            ll max_ = fun[i];
            while (indeg[curr] == 1 && curr != 0) {
                max_ = max(max_, fun[curr]);
                curr = conn[curr];
            }
            conn[i] = curr;
            fun[i] = max_;
        }
    }

    // tracking of sets of numbers set up
    V<multiset<ll>> vs(n + 1, multiset<ll>());
    for (int i = 1; i <= n; ++i) {
        vs[i].insert(fun[i]);
    }

    // calculate the number of leafs under a node
    int * leafs = (int *)calloc(n + 1, sizeof(int));
    calc_leafs(0, leafs, conns);

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    // fill results from root up
    while (!q.empty()) {
        auto top = q.front(); q.pop();
        if (top == 0) continue;
        // remove the smallest element (can I do this?)
        if (indeg[top] != 0) vs[top].erase(vs[top].begin());
        // merge smaller to larger
        if (vs[top].size() < vs[conn[top]].size()) {
            vs[conn[top]].insert(vs[top].begin(), vs[top].end());
        } else {
            vs[top].insert(vs[conn[top]].begin(), vs[conn[top]].end());
            vs[conn[top]] = vs[top];
        }
        // need to check if you have something from each leaf plus the parent
        if (vs[conn[top]].size() == leafs[conn[top]] + 1) {
            q.push(conn[top]);
        }
    }

    // calculate chain reaction that got to the end
    ll res = 0;
    for (auto v: vs[0]) {
        res += v;
    }
    cout << "Case #" << c << ": " << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve(i + 1);
    }
    
    return 0;
}

//
// Created by Jonny Keane on 2/12/22.
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

    graph D(6);
    D[0].pb(1);
    D[1].pb(2);
    D[2].pb(5);
    D[3].pb(0);
    D[3].pb(4);
    D[4].pb(1);
    D[4].pb(2);

    set<int> processed;
    vector<int> top_sort;
    stack<int> dfs;
    dfs.push(3);
    while (!dfs.empty()) {
        int top = dfs.top();
        bool successors_visited = true;
        for (int successor: D[top]) {
            if (processed.find(successor) == processed.end()) {
                successors_visited = false;
                dfs.push(successor);
            }
        }
        if (successors_visited) {
            dfs.pop();
            top_sort.pb(top);
            processed.insert(top);
        }
    }
    reverse(top_sort.begin(), top_sort.end());
    for (auto i: top_sort) {
        cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}
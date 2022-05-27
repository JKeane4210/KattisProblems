//
// Created by Jonny Keane on 5/21/22.
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

void dfs1(int curr, const vector<vector<int> > & conns, vector<bool> & visited, vector<int> & order) {
    visited[curr] = true;
    for (int conn: conns[curr]) {
        if (!visited[conn]) {
            dfs1(conn, conns, visited, order);
        }
    }
    order.push_back(curr);
}

void dfs2(int curr, const vector<vector<int> > & conns, vector<int> & comp, int curr_comp) {
    comp[curr] = curr_comp;
    for (int conn: conns[curr]) {
        if (comp[conn] == -1) {
            dfs2(conn, conns, comp, curr_comp);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int> > conns(n);
    vector<vector<int> > rev_conns(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        conns[i].push_back(x);
        rev_conns[x].push_back(i);
    }

    vector<bool> visited(n, false);
    vector<int> order;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, conns, visited, order);
        }
    }
    vector<int> comp(n, -1);
    int curr_comp = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (comp[order[i]] == -1) {
            dfs2(order[i], rev_conns, comp, curr_comp);
            ++curr_comp;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": " << comp[i] << endl;
    }
}
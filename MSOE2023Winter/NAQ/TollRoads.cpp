//
// Created by keanej on 2/7/2023.
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

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool same(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    V<unordered_set<int>> queries(n, unordered_set<int>());
    vpii sols(q, {0, 0}); // {min_dist, num_cities}
    for (int i = 0; i < m; ++i) {
        int a, b, t;
        cin >> a >> b >> t;
        --a; --b;
        auto p = mp(t, mp(a, b));
        pq.push(p);
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        queries[a].insert(i);
        queries[b].insert(i);
    }

    // perform Kruskal's to get MST edges
    UF unionFind(n);
    int connectionsMade = 0;
    int curr_w = pq.top().first;
    vpii w_sols;
    while(connectionsMade < n - 1) {
        auto top = pq.top();
        pq.pop();
        int a = top.second.first, b = top.second.second;
        int rep_a = unionFind.find(a); // logq
        int rep_b = unionFind.find(b); // logq
        if (rep_a != rep_b) {
            if (unionFind.size(rep_a) < unionFind.size(rep_b)) swap(rep_a, rep_b); // logq
            if (top.first != curr_w) {
                for (auto sol: w_sols) { // overall this will happen q times
                    sols[sol.first] = {curr_w, unionFind.size(sol.second)};
                }
                w_sols.clear();
                curr_w = top.first;
            }
            unionFind.join(rep_a, rep_b);

            if (queries[rep_a].size() > queries[rep_b].size()) {
                for (int query: queries[rep_b]) {
                    if (queries[rep_a].find(query) == queries[rep_a].end()) {
                        queries[rep_a].insert(query);
                    } else {
                        queries[rep_a].erase(query);
                        w_sols.pb({query, rep_a});
                    }
                }
            } else {
                for (int query: queries[rep_a]) {
                    if (queries[rep_b].find(query) == queries[rep_b].end()) {
                        queries[rep_b].insert(query);
                    } else {
                        queries[rep_b].erase(query);
                        w_sols.pb({query, rep_a});
                    }
                }
                queries[rep_a] = queries[rep_b];
            }

            ++connectionsMade;
            if (connectionsMade == n - 1) {
                for (auto sol: w_sols) { // overall this will happen q times
                    sols[sol.first] = {curr_w, unionFind.size(sol.second)};
                }
            }
        }
    }

    for (auto sol: sols) { // q
        cout << sol.first << " " << sol.second << endl;
    }

    return 0;
}
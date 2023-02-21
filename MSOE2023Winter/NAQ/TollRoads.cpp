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

// idea: can we keep track of the size at each fork => it's hard to say where to stop tho

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
    V<pair<int, pii>> edges;
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;
    V<set<int>> queries(n, set<int>());
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
    UF kruskalUnionFind(n);
    int connectionsMade = 0;
    while(connectionsMade < n - 1) {
        auto top = pq.top();
        pq.pop();
        int a = top.second.first, b = top.second.second;
        if (!kruskalUnionFind.same(a, b)) {
            kruskalUnionFind.join(a, b);
            edges.pb(top);
            ++connectionsMade;
        }
    }

    // union find for combining them
    UF unionFind(n);
    sort(edges.begin(), edges.end());

    int curr_w = edges[0].first;
    vpii w_sols;
    // processes edges in sorted order
    for (int i = 0; i < edges.size(); ++i) {
        if (q == 0) break;
        int rep_a = unionFind.find(edges[i].second.first);
        int rep_b = unionFind.find(edges[i].second.second);
        // if not together, merge them
        if (rep_a != rep_b) {
            // want |rep_a| to be >= |rep_b|
            if (unionFind.size(rep_a) < unionFind.size(rep_b)) swap(rep_a, rep_b);
            auto ap = queries[rep_a].begin();
            auto bp = queries[rep_b].begin();
            // add any queries that are satisfied
            while (ap != queries[rep_a].end() && bp != queries[rep_b].end()) {
                if (*ap > *bp) bp++; // b has smaller query index
                else if (*ap < *bp) ap++; // b has smaller query index
                else { // equal (shared query)
                    w_sols.pb({*ap, rep_a});
                    queries[rep_a].erase(ap++); // logn
                    queries[rep_b].erase(bp++); // logn
                }
            }
            // unite components
            unionFind.join(rep_a, rep_b);
            // update annotated queries: merge smaller to larger
            if (queries[rep_a].size() > queries[rep_b].size()) {
                queries[rep_a].insert(queries[rep_b].begin(), queries[rep_b].end());
            } else {
                queries[rep_b].insert(queries[rep_a].begin(), queries[rep_a].end());
                queries[rep_a] = queries[rep_b];
            }
        }
        // if you have processed all of a certain weight, solve solutions you can
        if (i == edges.size() - 1 || curr_w != edges[i + 1].first) {
            // update all solutions that pertain
            for (auto sol: w_sols) {
                sols[sol.first] = {curr_w, unionFind.size(sol.second)};
                q--;
            }
            w_sols.clear();
            if (curr_w != edges[i + 1].first)
                curr_w = edges[i + 1].first;
        }
    }

    for (auto sol: sols) {
        cout << sol.first << " " << sol.second << endl;
    }

    return 0;
}
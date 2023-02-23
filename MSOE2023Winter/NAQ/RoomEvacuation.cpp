//
// Created by keanej on 2/22/2023.
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

#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            // building the level graph
            while (qi < qe && !lvl[t]) { // while you haven't assigned a level to the sink
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            // add flow
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int deltas[5][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int N, M, T;

int get_node(int r, int c, int t, bool is_in) {
    return 2 + r * (2 * M * (T + 1)) + c * (2 * (T + 1)) + t * 2 + is_in;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> T;
    int SOURCE = 0;
    int SINK = 1;
    Dinic fg(2 * N * M * (T + 1) + 2);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k <= T; ++k) {
                int node = get_node(i, j, k, true);
                fg.addEdge(node, node - 1, 1, 0);
            }
        }
    }

    string grid[N];
    getline(cin, grid[0]);
    for (int i = 0; i < N; ++i) {
        getline(cin, grid[i]);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'P') {
                fg.addEdge(SOURCE, get_node(i, j, 0, true), 1, 0);
            }
            for (int k = 0; k < T; ++k) {
                if (grid[i][j] == 'E') {
                    fg.addEdge(get_node(i, j, k + 1, false), SINK, 1, 0);
                }
                for (auto delta: deltas) {
                    int nr = i + delta[0];
                    int nc = j + delta[1];
                    if (nr < 0 || nc < 0 || nr >= N || nc >= M || grid[nr][nc] == '#') continue;
                    fg.addEdge(get_node(i, j, k, false), get_node(nr, nc, k + 1, true), 1, 0);
                }
            }
        }
    }

    cout << fg.calc(SOURCE, SINK) << endl;

    return 0;
}

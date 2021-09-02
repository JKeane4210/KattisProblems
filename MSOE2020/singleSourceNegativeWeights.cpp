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

int INF = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, q, s;
    do {
        cin >> n >> m >> q >> s;
        int distances[n];
        tuple<int, int, int> edges[m];
        for (int i = 0; i < n; ++i) {
            distances[i] = INF;
        }
        for (int i = 0; i < m; ++i) {
            int a, b, w;
            cin >> a >> b >> w;
            edges[i] = make_tuple(a, b, w);
        }
        distances[s] = 0;
        vector<int> loops;
        for (int i = 0; i < (n - 1) * 2; ++i) {
            for (auto edge: edges) {
                int a, b, w;
                tie(a, b, w) = edge;
                distances[b] = min(distances[b], distances[a] + w);
                if (i >= n - 1) {
                    loops.pb(a);
                }
            }
        }
        for (int i = 0; i < q; ++i) {
            int dest;
            cin >> dest;
            if (distances[dest] == INF) {
                cout << "Impossible" << nl;
            } else if (find(loops.begin(), loops.end(), dest) != loops.end()) {
                cout << "-Infinity" << nl;
            } else {
                cout << distances[dest] << nl;
            }
        }
        cout << nl;
    } while (n != 0);

    return 0;
}

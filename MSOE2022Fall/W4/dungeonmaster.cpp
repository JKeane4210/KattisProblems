//
// Created by keanej on 10/4/2022.
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


// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

int deltas[6][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, -1, 0}, {0, 0, -1}};

void solve(int l, int r, int c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r, c;
    cin >> l >> r >> c;

    while (l != 0 || r != 0 || c != 0) {
        solve(l, r, c);
        cin >> l >> r >> c;
    }

    return 0;
}

void solve(int l, int r, int c) {
    bool visited[l][r][c];
    tuple<int, int, int, int> start;
    tuple<int, int, int> end;
    string grid[l][r];
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < r; ++j) {
            cin >> grid[i][j];
            for (int k = 0; k < c; ++k) {
                if (grid[i][j][k] == 'S') {
                    start = make_tuple(i, j, k, 0);
//                    cerr << i << " " << j << " " << k << endl;
                } else if (grid[i][j][k] == 'E') {
                    end = make_tuple(i, j, k);
//                    cerr << i << " " << j << " " << k << endl;
                }
                visited[i][j][k] = false;
            }
        }
    }
    

    queue<tuple<int, int, int, int>> q;
    q.push(start);
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (visited[get<0>(top)][get<1>(top)][get<2>(top)]) continue;
        visited[get<0>(top)][get<1>(top)][get<2>(top)] = true;
        if (get<0>(top) == get<0>(end) && get<1>(top) == get<1>(end) && get<2>(top) == get<2>(end)) {
            cout << "Escaped in " << get<3>(top) << " minute(s)." << endl;
            return;
        }
        for (auto delta: deltas) {
            int nl = get<0>(top) + delta[0];
            int nr = get<1>(top) + delta[1];
            int nc = get<2>(top) + delta[2];
            if (nl >= 0 && nl < l && nr >= 0 && nr < r && nc >= 0 && nc < c && grid[nl][nr][nc] != '#' && !visited[nl][nr][nc]) {
                q.push(make_tuple(nl, nr, nc, get<3>(top) + 1));
            }
        }
    }
    cout << "Trapped!" << endl;
}

//
// Created by Jonny Keane on 5/25/21.
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

const int directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

vector<string> paths;

void dfs(pair<int, int> currEmpty, int* lot, int m, int n, int r, int c, const string& path) {
    for(auto dir: directions) {
        if (currEmpty.first + dir[0] * 2 < m && currEmpty.first + dir[0] * 2 >= 0 &&
            currEmpty.second + dir[1] * 2 < n && currEmpty.second + dir[1] * 2 >= 0) {
            if (lot[(currEmpty.first + dir[0]) * n + currEmpty.second + dir[1]] != -2 &&
                    lot[(currEmpty.first + dir[0]) * n + currEmpty.second + dir[1]] ==
                    lot[(currEmpty.first + 2 * dir[0]) * n + currEmpty.second + 2 * dir[1]]) {
                if ((currEmpty.first + 2 * dir[0]) == r && currEmpty.second + 2 * dir[1] == c &&
                    path.find(" " + to_string(lot[(currEmpty.first + dir[0]) * n + currEmpty.second + dir[1]]) + " ") == string::npos) {
                    paths.push_back((path + to_string(lot[(currEmpty.first + dir[0]) * n + currEmpty.second + dir[1]])).substr(1));
                    return;
                }
                dfs(make_pair((currEmpty.first + 2 * dir[0]), currEmpty.second + 2 * dir[1]),
                    lot, m, n, r, c, path + to_string(lot[(currEmpty.first + dir[0]) * n + currEmpty.second + dir[1]]) + " ");
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    int lot[m * n];
    pair<int, int> empty = {0, 0};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> lot[i * n + j];
            if (lot[i * n + j] == -1) {
                empty = make_pair(i, j);
            }
        }
    }
    int r, c;
    cin >> r >> c;

    dfs(empty, lot, m, n, r - 1, c - 1, " ");
    if (!paths.empty()) {
        cout << *max_element(paths.begin(), paths.end()) << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
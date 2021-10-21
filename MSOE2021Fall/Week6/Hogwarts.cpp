//
// Created by Jonny Keane on 10/13/21.
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

int senior_config[1000][4];
int curr_config[1000][4];
int n;

vector<vector<int>> paths;

void dfs(int room, vector<int> seq, int depth) {
    if (depth > n) {
        return;
    }
    if (room == n - 1) {
        paths.emplace_back(seq);
    }
    for (int i = 0; i < 4; ++i) {
        int next_room = senior_config[room][i];
//        cout << room * n + i << "," << next_room << " ";
        if (next_room == -1) {
            continue;
        }
        vector<int> next_seq(seq);
        next_seq.push_back(i);
        dfs(next_room, next_seq, depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> senior_config[i][j];
           --senior_config[i][j];
//           cout << senior_config[i * n + j] << " ";
        }
//        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> curr_config[i][j];
            --curr_config[i][j];
//            cout << curr_config[i * n + j] << " ";
        }
//        cout << endl;
    }
    dfs(0, vector<int>(), 0);

    if (paths.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (const vector<int>& path: paths) {
        int curr = 0;
        for (int step: path) {
            if (curr_config[curr][step] == -1) {
                cout << "No" << endl;
                return 0;
            } else {
                curr = curr_config[curr][step];
            }
        }
        if (curr != n - 1) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
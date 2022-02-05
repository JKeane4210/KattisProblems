//
// Created by Jonny Keane on 1/29/22.
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

    V<string> grid = {"123", "456", "789", " 0 "};
    set<int> solutions;
    queue<pair<pair<int, int>, string>> q;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] != ' ') {
                q.push(make_pair(make_pair(i, j), grid[i].substr(j, 1)));
            }
        }
    }
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        int solution = stoi(top.second);
        if (solution > 250 || solutions.count(solution) != 0) continue;
        solutions.insert(solution);
        for (int i = top.first.first; i < grid.size(); ++i) {
            for (int j = top.first.second; j < grid[0].size(); ++j) {
                if (grid[i][j] == ' ') continue;
                q.push(make_pair(make_pair(i, j), top.second + grid[i].substr(j, 1)));
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        int res;
        int min_dist = INT_MAX;
        for (int solution: solutions) {
            if (abs(solution - val) < min_dist) {
                min_dist = abs(solution - val);
                res = solution;
            }
        }
        cout << res << endl;
    }

    return 0;
}
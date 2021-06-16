//
// Created by Jonny Keane on 6/13/21.
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

const pair<int, int> deltas[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool isSolvable(bitset<16> visited, vector<pair<int, int>> starts, vector<pair<int,int>> ends, int currColor, pair<int, int> currLoc) {
//    cout << currLoc.first << " " << currLoc.second << ": " << currColor << endl;
    if (~visited == 0 && currColor == starts.size()) {
        return true;
    }
    if (abs(currLoc.first - ends[currColor].first) + abs(currLoc.second - ends[currColor].second) == 1) {
        if (isSolvable(visited, starts, ends, currColor + 1, currColor < 3 ? starts[currColor + 1] : make_pair(0, 0))) {
            return true;
        }
    }
    for (auto delta: deltas) {
        int r = currLoc.first + delta.first;
        int c = currLoc.second + delta.second;
        if (r >= 0 && r < 4 && c >= 0 && c < 4 && !visited[r * 4 + c]) {
            bitset<16> nextVisited(visited);
            nextVisited[r * 4 + c] = true;
            if (abs(r - ends[currColor].first) + abs(c - ends[currColor].second) == 1) {
                if (isSolvable(nextVisited, starts, ends, currColor + 1, currColor < 3 ? starts[currColor + 1] : make_pair(0, 0))) {
                    return true;
                }
            }
            if (isSolvable(nextVisited, starts, ends, currColor, make_pair(r, c))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string grid[4];
    for (int i = 0; i < 4; ++i) {
        cin >> grid[i];
    }
    vector<pair<int, int>> starts;
    vector<pair<int, int>> ends;
    map<char, int> colors;
    bitset<16> currVisited;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] != 'W') {
                currVisited[i * 4 + j] = true;
                if (colors.find(grid[i][j]) == colors.end()) {
                    colors[grid[i][j]] = colors.size();
                    starts.emplace_back(make_pair(i, j));
                    ends.emplace_back(make_pair(0, 0));
                } else {
                    ends[colors[grid[i][j]]] = make_pair(i, j);
                }
            }
        }
    }
    if (isSolvable(currVisited, starts, ends, 0, starts[0])) {
        cout << "solvable" << endl;
    } else {
        cout << "not solvable" << endl;
    }

    return 0;
}

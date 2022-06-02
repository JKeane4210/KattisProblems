//
// Created by keanej on 5/31/2022.
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

int deltas[4][2] = {
        {1,  0},
        {0,  1},
        {-1, 0},
        {0,  -1}
};

char dirs[4] = {'v', '>', '^', '<'};

bool searched[500][500];
int num_sights[500][500];
bool visited[500][500];
int cycle[500][500];

void search(pii curr, unordered_set<int> & base, string * grid, int r, int c, const pii & first, int encountered_cycle) {
    searched[curr.first][curr.second] = true;
    // add new sights
    for (auto delta: deltas) {
        int poss_sight_r = curr.first + delta[0];
        int poss_sight_c = curr.second + delta[1];
        if (poss_sight_r >= 0 && poss_sight_r < r && poss_sight_c >= 0 && poss_sight_c < c && grid[poss_sight_r][poss_sight_c] == '#') {
            base.insert(poss_sight_r * 500 + poss_sight_c);
        }
    }
    // set how many sights you can see from this location
    num_sights[curr.first][curr.second] = base.size();
//    visited[curr.first][curr.second] = true;
    // search backwards recursively if can go up the river
    for (int k = 0; k < 4; ++k) {
        int poss_river_r = curr.first - deltas[k][0];
        int poss_river_c = curr.second - deltas[k][1];
        pii next = mp(poss_river_r, poss_river_c);
        if (poss_river_r >= 0 && poss_river_r < r && poss_river_c >= 0 && poss_river_c < c && grid[poss_river_r][poss_river_c] == dirs[k] && next != first) {
            search(next, base, grid, r, c, first, encountered_cycle);
        }
    }
    searched[curr.first][curr.second] = false;
    // remove sites if they have no connections currently
    for (auto delta: deltas) {
        int poss_sight_r = curr.first + delta[0];
        int poss_sight_c = curr.second + delta[1];
        if (poss_sight_r >= 0 && poss_sight_r < r && poss_sight_c >= 0 && poss_sight_c < c && grid[poss_sight_r][poss_sight_c] == '#') {
            bool any = false;
            for (auto d2: deltas) {
                int check_vis_r = poss_sight_r + d2[0];
                int check_vis_c = poss_sight_c + d2[1];
                if (check_vis_r >= 0 && check_vis_r < r && check_vis_c >= 0 && check_vis_c < c && (searched[check_vis_r][check_vis_c] || cycle[check_vis_r][check_vis_c] == encountered_cycle)) {
                    any = true;
                    break;
                }
            }
            if (!any) {
                base.erase(base.find(poss_sight_r * 500 + poss_sight_c));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(searched[0], searched[0] + 250000, false);
    fill(num_sights[0], num_sights[0] + 250000,  -1);
    fill(visited[0], visited[0] + 250000, false);
    fill(cycle[0], cycle[0] + 250000,  -1);

    int r, c;
    cin >> r >> c;
    string grid[r];
    for (int i = 0; i < r; ++i) {
        cin >> grid[i];
    }

    int cycle_index = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] == '.' || grid[i][j] == '#' || num_sights[i][j] != -1) continue;
            int curr_r = i, curr_c = j;
            vpii path;
            unordered_set<int> base;
            int encountered_cycle = -2;
            while (true) {
                // if out of bounds or on land, you are done
                if (curr_r >= 0 && curr_r < r && curr_c >= 0 && curr_c < c && grid[curr_r][curr_c] != '.' && grid[curr_r][curr_c] != '#') {
                    // if you have seen this river piece before, you are in a cycle
                    if (visited[curr_r][curr_c]) {
                        pii cycle_start = mp(curr_r, curr_c);
                        bool in_cycle = false;
                        unordered_set<int> cycle_sights;
                        // find where the cycle actually begins, and create base of all sites accessible by the sight
                        for (pii loc: path) {
                            if (loc == cycle_start) in_cycle = true;
                            if (in_cycle) {
                                cycle[loc.first][loc.second] = cycle_index;
                                for (auto delta: deltas) {
                                    int poss_site_r = delta[0] + loc.first;
                                    int poss_site_c = delta[1] + loc.second;
                                    if (poss_site_r >= 0 && poss_site_r < r && poss_site_c >= 0 && poss_site_c < c && grid[poss_site_r][poss_site_c] == '#') {
                                        cycle_sights.insert(poss_site_r * 500 + poss_site_c);
                                    }
                                }
                            }
                        }
                        // make sure the base of the search contains this
                        base = cycle_sights;
                        encountered_cycle = cycle_index++;
                        break;
                    }
                    // else, visit the river and keep traversing down it
                    visited[curr_r][curr_c] = true;
                    path.pb(mp(curr_r, curr_c));
                    if (grid[curr_r][curr_c] == '>') ++curr_c;
                    else if (grid[curr_r][curr_c] == '<') --curr_c;
                    else if (grid[curr_r][curr_c] == 'v') ++curr_r;
                    else if (grid[curr_r][curr_c] == '^') --curr_r;
                } else break; // base should be empty because reached land/out of bounds
            }
            search(path[path.size() - 1], base, grid, r, c, path[path.size() - 1], encountered_cycle);
        }
    }

    int res = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (grid[i][j] != '.' && grid[i][j] != '#') {
                res = max(res, num_sights[i][j]);
            }
        }
    }

    cout << res << endl;

    return 0;
}

//
// Created by Jonny Keane on 2/5/22.
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

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

class trie_node {
public:
    map<char, trie_node> conns;
    bool is_word = false;
};

int deltas[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    cin >> h >> w;
    V<string> grid(h);
    for (int i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    set<string> needed_prefs;
    set<string> words;
    set<string> found;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        words.insert(s);
        for (int j = 1; j <= s.length(); ++j) {
            needed_prefs.insert(s.substr(0, j));
        }
    }
    queue<pair<pair<string, set<pii>>, pii>> q;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            string start(1, grid[i][j]);
            if (words.find(start) != words.end()) {
                found.insert(start);
            }
            set<pii> start_set = {mp(i, j)};
            q.push(mp(mp(start, start_set), mp(i, j)));
        }
    }
    while (!q.empty()) {
        auto top = q.front();
        q.pop();
        if (top.first.first.size() >= 10) continue;
        for (auto delta: deltas) {
            int nr = top.second.first + delta[0];
            int nc = top.second.second + delta[1];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && top.first.second.find(mp(nr, nc)) == top.first.second.end()) {
                string step = top.first.first + string(1, grid[nr][nc]);
                if (needed_prefs.find(step) == needed_prefs.end()) continue;
                if (words.find(step) != words.end()) {
                    found.insert(step);
                }
                set<pii> step_set(top.first.second);
                step_set.insert(mp(nr, nc));
                q.push(mp(mp(top.first.first + string(1, grid[nr][nc]), step_set), mp(nr, nc)));
            }
        }
    }
    cout << found.size() << endl;

    return 0;
}

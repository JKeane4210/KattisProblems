//
// Created by keanej on 5/27/2023.
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

bool is_opp(char a, char b) {
    if (a == 'L' && b == 'R') return true;
    if (a == 'R' && b == 'L') return true;
    if (a == 'U' && b == 'D') return true;
    if (a == 'D' && b == 'U') return true;
    return false;
}

map<char, pii> deltas = {{'L', {-1, 0}},
                         {'R', {1, 0}},
                         {'U', {0, 1}},
                         {'D', {0, -1}}};

void test(int cx, int cy, const vpii & blocks, string s) {
    cout << "--- testing ---" << endl;
    for (int i = 0; i < s.length(); ++i) {
        for (auto block: blocks) {
            if (block.first == cx && ((s[i] == 'D' && block.second < cy) || (s[i] == 'U' && block.second > cy))) {
                cout << cx << " " << cy << " " << s[i] << " -> [" << block.first << " " << block.second << "] -> ";
                cy = block.second - ((block.second - cy) / abs(block.second - cy));
                break;
            } else if (block.second == cy && ((s[i] == 'L' && block.first < cx) || (s[i] == 'R' && block.first > cx))) {
                cout << cx << " " << cy << " " << s[i] << " -> [" << block.first << " " << block.second << "] -> ";
                cx = block.first - ((block.first - cx) / abs(block.first - cx));
                break;
            }
        }
        cout << cx << " " << cy << endl;
    }
    cout << "ended: " << cx << " " << cy << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    mt19937 mt(time(nullptr));
    string s;
    cin >> s;
    if (s.size() >= 3 &&
            is_opp(s[s.size() - 1], s[s.size() - 2]) &&
            is_opp(s[s.size() - 2], s[s.size() - 3])) {
        cout << "impossible" << endl;
        return 0;
    }
    int BIG = 50000000;
    vector<pii> blocks;
    int cx = 0, cy = 0;
    int i = s.size() - 1;
    while (i >= 0) {
        char move = s[i], prev = i < s.size() - 1 ? s[i + 1] : 0;
        pii delta = deltas[move];
        // create block next to block current direction move
        int mbx = cx + delta.first;
        int mby = cy + delta.second;
        blocks.pb({mbx, mby});
        // choose a random end delta
        int end = BIG / 2 + abs((int)mt()) % (BIG / 2);
        if (is_opp(move, prev)) {
            // choose delta that is in the middle
            int mid = BIG / 4 + ((int)mt() % (end - 2 - (BIG / 4)));
            while (i >= 1 && is_opp(s[i], s[i - 1])) i--;
            i--;
            // create a new block at the end delta
            int bx = cx - delta.first * end;
            int by = cy - delta.second * end;
            blocks.pb({bx, by});
            // update location to random point in the middle (based on delta)
            cx = cx - delta.first * mid;
            cy = cy - delta.second * mid;
        } else {
            // update location with end delta
            cx = cx - delta.first * end;
            cy = cy - delta.second * end;
            i--;
        }
//        cout << "*" << i<< " " << cx << " " << cy << endl;
    }
    cout << cx << " " << cy << endl;
    cout << blocks.size() << endl;
    for (auto block : blocks) {
        cout << block.first << " " << block.second << endl;
    }
    test(cx, cy, blocks, s);

    return 0;
}
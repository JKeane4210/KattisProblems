//
// Created by Jonny Keane on 3/19/22.
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

pii y_range(int y, int n, const vi & v) {
    int l = 0, r = v.size() - 1;
    int upper = 0, lower = n + 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (y + v[mid] <= n && y + v[mid] >= 1) {
            upper = max(upper, y + v[mid]);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (y + v[mid] <= n && y + v[mid] >= 1) {
            lower = min(lower, y + v[mid]);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    if (upper == 0) {
        return mp(0, 0);
    } else {
        return mp(upper, lower);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    pii a, b;
    cin >> n >> a.first >> a.second >> b.first >> b.second;
    vi vert_changes[2 * n + 1];
    set<pii> moves;
    vi b_moves[n + 1];
    for (int i = 0; i < n; ++i) {
        pii move;
        cin >> move.first >> move.second;
        moves.insert(move);
        if (b.first + move.first >= 1 && b.first + move.first <= 1 &&
            b.second + move.second >= 1 && b.second + move.second <= n) {
                b_moves[b.first + move.first].pb(b.second + move.second);
        }
        vert_changes[move.first + n].pb(move.second);
    }
    for (int i = 0; i < 2 * n - 1; ++i) {
        if (vert_changes[i].size() > 1) {
            sort(vert_changes[i].begin(), vert_changes[i].end());
        }
    }
    // nlogn for seeing if alice wins
    pii bounds = y_range(a.second, n, vert_changes[b.first - a.first + n]);
    if (bounds != mp(0, 0) && b.second <= bounds.first && b.second >= bounds.second) {
        cout << "Alice wins" << endl;
        return 0;
    }
    for (auto move: moves) {
        pii a2 = mp(a.first + move.first, a.second + move.second);
        if (a2.first > n || a2.first < 1 || a2.second > n || a2.second < 1) continue;
        if (vert_changes[b.first - a2.first + n].empty()) continue;
        bounds = y_range(a2.second, n, vert_changes[b.first - a2.first + n]);
        if (bounds != mp(0, 0) && b.second <= bounds.first && b.second >= bounds.second) {
            cout << "Alice wins" << endl;
            return 0;
        }
    }
    srand(3141592);
    set<pii> rand_moves;
    while (rand_moves.size() < min(200, n * n - 1)) {
        pii r = mp(rand() % n + 1, rand() % n + 1);
//        cout << r.first << " " << r.second << endl;
        if (r != b) {
            rand_moves.insert(r);
        }
    }
    pii tie = mp(0, 0);
    for (auto tie_move: rand_moves) {
        bounds = y_range(b.second, n, vert_changes[tie_move.first - b.first + n]);
        if (bounds != mp(0, 0) && tie_move.second <= bounds.first && tie_move.second >= bounds.second) { // if you can find dest from one point
            continue;
        } else {
            bool found_one = false;
            for (auto move: moves) {
                pii b2 = mp(b.first + move.first, b.second + move.second);
                if (b2.first > n || b2.first < 1 || b2.second > n || b2.second < 1) continue;
                if (vert_changes[tie_move.first - b2.first + n].empty()) continue;
                bounds = y_range(b2.second, n, vert_changes[tie_move.first - b2.first + n]);
                if (bounds != mp(0, 0) && tie_move.second <= bounds.first && tie_move.second >= bounds.second) {
                    found_one = true;
                    break;
                }
            }
            if (!found_one) {
                tie = tie_move;
                break;
            }
        }
    }
    if (tie == mp(0, 0)) { // if all rand_moves could be found by Bob
        cout << "Bob wins" << endl;
    } else {
        cout << "tie " << tie.first << " " << tie.second << endl;
    }

    return 0;
}
/*
4
1 1
3 4
0 3
2 0
0 -3
2 3


 */
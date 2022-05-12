//
// Created by Jonny Keane on 4/8/22.
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

void solve(int num) {
    int e, w;
    cin >> e >> w;
//    cout << e << w << endl;
    int exercises[e][w];
    int dp_lifetime[w][e][e + 1]; // weight, start_exercise, life_time_length - 1
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < e; ++j) {
            for (int k = 0; k <= e; ++k) {
                dp_lifetime[i][j][k] = 0;
            }
        }
    }

    for (int i = 0; i < e; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> exercises[i][j];
        }
    }
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < e; ++j) {
            dp_lifetime[i][j][0] = exercises[j][i];
        }
    }
    for (int i = 0; i < w; ++i) { // for each weight
        for (int j = 0; j < e; ++j)  { // for each starting point
            for (int k = 1; k < e; ++k) { // for each length, starting at length "2"
                if (j + k >= e) continue;
                dp_lifetime[i][j][k] = min(dp_lifetime[i][j][k - 1], exercises[j + k][i]);
            }
        }
    }
//    for (int i = 0; i < w; ++i) {
//        cout << "Weight " << i << endl;
//        for (int j = 0; j < e; ++j) {
//            for (int k = 0; k <= e; ++k) {
//                cout << dp_lifetime[i][j][k] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
    int curr_counts[w];
    for (int i = 0; i < w; ++i) {
        curr_counts[i] = 0;
    }
    int total_moves = 0;
    vector<pii> removals[e + 1]; // weight_type, number
    for (int i = 0; i <= e; ++i) {
        removals[i] = vpii();
    }
//    cout << "Hi" << endl;
    for (int i = 0; i < e; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << curr_counts[j] << " ";
        }
        cout << endl;
        for (auto removal: removals[i]) {
            curr_counts[removal.first] -= removal.second;
            total_moves += removal.second;
            cout << "removing " << removal.second << " weight "  << removal.first << " step " << i << endl;
        }
        vector<pii> adds;
//        cout << "Round " << i << endl;
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < e; ++k) {
                // for a given weight, if the number of weights persisting decreases
                if ((i == 0 || dp_lifetime[j][i][k] > curr_counts[j]) && dp_lifetime[j][i][k] > dp_lifetime[j][i][k + 1]) {
                    adds.pb(mp(k, j)); // length, weight type
                }
            }
        }
        bool used[w];
        for (int j = 0; j < w; ++j) {
            used[w] = false;
        }
        for (auto p: adds) {
            pii add_pair = mp(p.second, dp_lifetime[p.second][i][p.first] - dp_lifetime[p.second][i][p.first + 1]);
            if (!used[add_pair.first]) {
                used[add_pair.first] = true;
                add_pair.second -= curr_counts[add_pair.first];
            }
            if (i + p.first + 1 > e) continue;
            total_moves += add_pair.second;
            curr_counts[p.second] += add_pair.second;
            removals[i + p.first + 1].pb(add_pair);
            cout << "adding " << add_pair.second << " weight " << add_pair.first << " step " << i << endl;
        }
    }
    for (int j = 0; j < w; ++j) {
        cout << curr_counts[j] << " ";
    }
    cout << endl;
    for (auto removal: removals[e]) {
        curr_counts[removal.first] -= removal.second;
        total_moves += removal.second;
        cout << "removing " << removal.second << " weight "  << removal.first << " step cleanup" << endl;
    }
    for (int j = 0; j < w; ++j) {
        cout << curr_counts[j] << " ";
    }
    cout << endl;
    cout << "Case #" << num << ": " << total_moves << endl;
}

//

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i= 1; i <= n; ++i) {
        solve(i);
    }

    return 0;
}
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

unordered_map<string, int> value = {{"A", 1},
                                    {"2", 2},
                                    {"3", 3},
                                    {"4", 4},
                                    {"5", 5},
                                    {"6", 6},
                                    {"7", 7},
                                    {"8", 8},
                                    {"9", 9},
                                    {"T", 10},
                                    {"J", 10},
                                    {"Q", 10},
                                    {"K", 10}
                                    };

unordered_map<string, int> order = {{"A", 1},
                                    {"2", 2},
                                    {"3", 3},
                                    {"4", 4},
                                    {"5", 5},
                                    {"6", 6},
                                    {"7", 7},
                                    {"8", 8},
                                    {"9", 9},
                                    {"T", 10},
                                    {"J", 11},
                                    {"Q", 12},
                                    {"K", 13}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
//    n = 100;
    string hand[n];
    unordered_map<string, int> count;
    map<int, int> ord;
    int val[n];
    for (int i = 0; i < n; ++i) {
        cin >> hand[i];
//        hand[i] = "5";
        if (ord.find(order[hand[i]]) == ord.end()) {
            ord[order[hand[i]]] = 0;
        }
        ord[order[hand[i]]]++;
        val[i] = value[hand[i]];
        if (count.find(hand[i]) == count.end()) {
            count[hand[i]] = 0;
        }
        count[hand[i]]++;
    }
    ll score = 0;
    // pairs
    for (auto & p: count) {
        if (p.second >= 2) {
            score += p.second * (p.second - 1);
        }
    }
//    cout << score << endl;
    // 15's
    ll dp[n + 1][16];
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i == 0;
        for (int j = 1; j < 16; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 15; ++j) {
            dp[i + 1][j] += dp[i][j]; // not selecting the card
            if (j + val[i] <= 15) {
                dp[i + 1][j + val[i]] += dp[i][j]; // selecting the card
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        score += 2 * dp[i][15];
    }
//    for (int i = 0; i <= 15; ++i) {
//        cout << i % 10 << " ";
//    } cout << endl;
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j < 16; ++j) {
//            cout << dp[i][j] << " ";
//        } cout << endl;
//    }
//    cout << score << endl;
    // runs
    int prev = -1;
    ll c = 0;
    ll poss = 1;
    for (auto p: ord) {
//        cout << p.first << endl;
        if (p.first != prev + 1) {
//            cout << c << " " << poss << endl;
            if (c >= 3) {
                score += poss * c;
            }
            c = 1;
            poss = p.second;
        } else {
            c++;
            poss *= p.second;
        }
        prev = p.first;
    }
//    cout << c << " " << poss << endl;
    if (c >= 3) {
        score += poss * c;
    }
    cout << score << endl;
    return 0;
}
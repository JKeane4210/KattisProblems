//
// Created by keanej on 9/17/2022.
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

// brute force
// recursive solution where you only fork when you need to

// what a dp would represent
// minimum number of queries that would end with search engine j for query i

int MAX = INT_MAX;

void solve(int case_num) {
    string s_;
    getline(cin, s_);
    int s = stoi(s_);
    string engines[s];
    for (int i = 0; i < s; ++i) {
        getline(cin, engines[i]);
    }
    string q_;
    getline(cin, q_);
    int q = stoi(q_);
    string queries[q];
    for (int i = 0; i < q; ++i) {
        getline(cin, queries[i]);
    }
    int dp[q + 1][s];
    for (int i = 0; i <= q; ++i) {
        for (int j = 0; j < s; ++j) {
            dp[i][j] = i == 0 ? 0 : MAX;
        }
    }
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < s; ++j) {
            if (queries[i] == engines[j]) {
                for (int k = 0; k < s; ++k) {
                    if (k == j || dp[i][j] == MAX) continue;
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + 1);
                }
            } else {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
    }
//    for (int i = 0; i <= q; ++i) {
//        for (int j = 0; j < s; ++j) {
//            cout << dp[i][j] << "\t";
//        } cout << endl;
//    }
    int res = INT_MAX;
    for (int i = 0; i < s; ++i) {
        res = min(res, dp[q][i]);
    }
    cout << "Case #" << case_num << ": " << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string T_;
    getline(cin, T_);
    int T = stoi(T_);
    for (int i = 0; i < T; ++i) {
        solve(i + 1);
    }

    return 0;
}
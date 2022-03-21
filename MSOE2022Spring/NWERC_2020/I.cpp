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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long travels[n];
    long times[3][n];
    for (int i = 0; i < n; ++i) {
        cin >> travels[i];
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> times[i][j];
        }
    }
    pll durations[3][n];
    for (int i = 0; i < 3; ++i) {
        durations[i][0] = mp(0, times[i][0]);
    }
    for (int i = 0; i < 3; ++i) {
        cout << durations[i][0].first << "-" << durations[i][0].second << " ";
        for (int j = 1; j < n; ++j) {
            long start = durations[i][j - 1].second + travels[i - 1];
            durations[i][j] = mp(start, start + times[i][j]);
            cout << durations[i][j].first << "-" << durations[i][j].second << " ";
        }
        cout << endl;
    }
    int c_ind = 0;
    long c_offset = 0;
    int b_ind = 0;
    long b_offset = 0;
    for (int i = 0; i < n; ++i) {
        while (durations[1][i].first + b_offset < durations[0][i].second) {
            b_ind = (b_ind + n - 1) % n;
            b_offset += times[1][b_ind] + travels[b_ind];
        }
        while (durations[2][i].first + c_offset < durations[1][i].second + b_offset) {
            c_ind = (c_ind + n - 1) % n;
            c_offset += times[2][c_ind] + travels[c_ind];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << durations[0][i].first << "-" << durations[0][i].second << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << durations[1][i].first + b_offset << "-" << durations[1][i].second + b_offset << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << durations[2][i].first + c_offset << "-" << durations[2][i].second + c_offset << " ";
    }
    cout << endl;
    cout << b_ind + 1 << " " << c_ind + 1 << endl;
    return 0;
}
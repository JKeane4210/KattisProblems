//
// Created by Jonny Keane on 3/3/22.
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

const char open[4] = {'(', '{', '[', '<'};
const char close[4] = {')', '}', ']', '>'};

int is_open(char c) {
    for (int i = 0; i < 4; ++i) {
        if (open[i] == c) {
            return i;
        }
    }
    return -1;
}

int is_close(char c) {
    for (int i = 0; i < 4; ++i) {
        if (close[i] == c) {
            return i;
        }
    }
    return -1;
}

long dp[20][20];

long count_possibilities(int a, int b, int lim, bool first = false) {
//    if (first) cout << "*";
//    cout << a << " " << b << endl;
    if (a + 1 == b) {
        return dp[a][b];
    }
    long res = 0;
    if (dp[a][b] != 0) { // whole range
        res += dp[a][b] * count_possibilities(a + 1, b - 1, b - a - 1);
    }
    for (int i = a + 2; i < a + lim; i += 2) { // for every start
        if (dp[i][b] != 0) { // if there are pairings
//            if (first) cout << "#" << endl;
            res += count_possibilities(a, i - 1, i - a) * count_possibilities(i, b, 2);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); j += 2) {
            int o = is_open(s[i]);
            int c = is_close(s[j]);
            if ((o != -1 && (o == c || s[j] == '?')) || (c != -1 && (o == c || s[i] == '?'))) {
                ++dp[i][j];
            } else if (s[i] == '?' && s[j] == '?') {
                dp[i][j] += 4;
            }
        }
    }

//    for (int i = 0; i < s.size(); ++i) {
//        for (int j = 0; j < s.size(); ++j) {
//            cout << dp[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout << count_possibilities(0, s.size() - 1, s.size(), true) << endl;

    return 0;
}
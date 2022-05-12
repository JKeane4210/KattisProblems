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
    string s;
    cin >> s;
    string res;
    for (int i = 0; i < s.length() - 1; ++i) {
        int j = i + 1;
        while (s[i] == s[j] && j < s.length()) {
            ++j;
        }
        if (j != s.length() && s[i] < s[j]) {
            res += string(2, s[i]);
        } else {
            res += string(1, s[i]);
        }
    }
    res += string(1, s[s.length() - 1]);
    cout << "Case #" << num << ": " << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        solve(i);
    }

    return 0;
}
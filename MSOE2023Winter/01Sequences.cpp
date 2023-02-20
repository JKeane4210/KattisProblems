//
// Created by keanej on 1/30/2023.
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

ll MOD = 1000000007;

ll seqs(const string & s) {
    int n = (int)s.length();
    vll poss_pow = vll();
    poss_pow.pb(0);
    poss_pow.pb(1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            poss_pow.pb((poss_pow[poss_pow.size() - 1] * 2) % MOD);
        }
    }
    ll ones = 0;
    ll ones_div_2 = 0;
    ll shifts = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones = (ones + poss_pow[poss_pow.size() - 1]) % MOD;
            ones_div_2 = (ones_div_2 + poss_pow[poss_pow.size() - 2]) % MOD;
        } else if (s[i] == '0') {
            shifts = (shifts + ones) % MOD;
        } else if (s[i] == '?') {
            shifts = (shifts + ones_div_2) % MOD;
            ones = (ones + poss_pow[poss_pow.size() - 2]) % MOD;
            ones_div_2 = (ones_div_2 + poss_pow[poss_pow.size() - 3]) % MOD;
        }
    }
    return shifts;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    cout << seqs(s) << endl;

    return 0;
}
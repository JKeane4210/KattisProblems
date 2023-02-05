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

// idea handle it reversed (mentality of pushing 0's left)
ll seqs(const string & s, int i, int ones) {
    if (i == s.length()) return 0;
    if (s[i] == '0') {
        return ones + seqs(s, i + 1, ones); // ned some way of handling how many times this happens
    } else if (s[i] == '1') {
        return seqs(s, i + 1, ones + 1);
    } else { // '?'
       return ones + seqs(s, i + 1, ones) + seqs(s, i + 1, ones + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    cout << seqs(s, 0, 0) << endl;

    return 0;
}
//
// Created by keanej on 9/27/2022.
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
    int start = (1 << (n + 1)) - 1;
    string s;
    getline(cin, s);
    int remove = 1;
    int val = 0;
    for (char c: s) {
        if (c != 'L' && c != 'R') continue;
        if (c == 'L') {
            val |= 1;
        }
        remove <<= 1;
        start -= remove;
        val <<= 1;
    }
    val >>= 1;
    cout << val + start << endl;

    return 0;
}
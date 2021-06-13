//
// Created by Jonny Keane on 6/6/21.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    double res = 0;
    double probs[n];
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s >> probs[i - 1];
    }
    sort(probs, probs + n);
    for (int i = 1; i <= n; ++i) {
        res += (double)i * probs[n - i];
    }
    printf("%.10f", res);
    return 0;
}
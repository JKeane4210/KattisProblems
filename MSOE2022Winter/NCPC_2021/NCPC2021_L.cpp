//
// Created by Jonny Keane on 2/8/22.
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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int res = INT_MAX;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int y, a, b;
        cin >> y >> a >> b;
        int gcd_ = gcd(a, b);
        int next = y + (a / gcd_) * (b / gcd_) * gcd_;
        res = min(res, next);
    }
    cout << res << endl;


    return 0;
}
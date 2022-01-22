//
// Created by Jonny Keane on 1/19/22.
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

long gcd(long a, long b) { // b is greater
    long mod = b % a;
    if (mod == 0) {
        return a;
    } else {
        return gcd(mod, b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    long gcd_ = gcd(a, b);
    cout << gcd(a / gcd_, b) << endl;
//    cout << gcd(a,  b);
//6329976646473
//40318322589
    return 0;
}
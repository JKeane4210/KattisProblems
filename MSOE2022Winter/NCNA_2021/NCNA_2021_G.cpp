//
// Created by Jonny Keane on 2/28/22.
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

    int a1, a2;
    string s;
    cin >> a1 >> a2 >> s;
    if (a1 + 3 == a2 && s == "ABBA") {
        cout << a1 + 1 << " " << a1 + 2 << endl;
    } else if (a1 == 3 && s == "BBAA") {
        cout << 1 << " " << 2 << endl;
    } else if (a2 == 7 && s == "AABB") {
        cout << 8 << " " << 9 << endl;
    } else if (a1 == 6 && a2 == 8 && s == "ABAB") {
        cout << 7 << " " << 9 << endl;
    } else if (a1 == 2 && a2 == 4 && s == "BABA") {
        cout << 1 << " " << 3 << endl;
    } else if (a1 == 2 && a2 == 8 && s == "BAAB") {
        cout << 1 << " " << 9 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}
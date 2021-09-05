//
// Created by Jonny Keane on 9/4/21.
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

//int ANS[INT_MAX];

void solve(int n) {
    if (n == 3) {
        cout << 4 << endl;
        return;
    }
    if (n - 3 <= 3) {
        cout << "No such base" << endl;
        return;
    }
//    cout << ANS[n - 3] << endl;
    int goal = n - 3;
    int f = 1;
    int res = INT_MAX;
    while (f * f <= goal) {
        if (goal % f == 0) {
            if (f > 3) {
                cout << f << endl;
                return;
            }
            if (goal / f > 3) {
                res = min(res, goal / f);
            }
        }
        ++f;
    }
    cout << res << endl;
}

int main() {
    int GOAL = 200;
    ios::sync_with_stdio(false);
    cin.tie(0);
//    for (long i = 7; i <= GOAL - 3; ++i) {
//        ANS[i] = -1;
//    }
//    for (int i = 7; i <= GOAL - 3; ++i) {
//        if (ANS[i] != -1) continue;
//        int delta = i - 3;
//        for (long j = i; j <= GOAL - 3; j += delta) {
//            if (ANS[j] != -1) continue;
//            ANS[j] = delta;
//        }
//    }
//    cout << "DONE" << endl;
    int n;
    cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }

    return 0;
}
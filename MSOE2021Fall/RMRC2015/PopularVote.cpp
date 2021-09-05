//
// Created by Jonny Keane on 9/3/21.
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

void solve() {
    int n;
    cin >> n;
    bool multi_max = false;
    int winner = 0;
    int max_ = 0;
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        int votes;
        cin >> votes;
        total += votes;
        if (votes > max_) {
            max_ = votes;
            winner = i;
            multi_max = false;
        } else if (votes == max_) {
            multi_max = true;
        }
    }
    if (multi_max) {
        cout << "no winner" << endl;
        return;
    }
//    cout << total << " " << total / 2 + 1 << endl;
    if (max_ > total / 2) {
        cout << "majority winner " << winner << endl;
    } else {
        cout << "minority winner " << winner << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}
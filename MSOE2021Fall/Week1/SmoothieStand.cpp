//
// Created by Jonny Keane on 9/6/21.
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

    int k, r;
    cin >> k >> r;
    int max_profit = 0;
    int ing[k];
    for (int i = 0; i < k; ++i) {
        cin >> ing[i];
    }
    for (int i = 0; i < r; ++i) {
        int price;
        int max_amount = INT_MAX;
        for (int j = 0; j < k; ++j) {
            int val;
            cin >> val;
            if (val == 0) continue;
            int can_make = ing[j] / val;
            max_amount = min(max_amount, can_make);
        }
        cin >> price;
        max_profit = max(max_amount * price, max_profit);
    }
    cout << max_profit << endl;

    return 0;
}
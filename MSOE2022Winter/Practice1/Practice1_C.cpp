//
// Created by Jonny Keane on 1/29/22.
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
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        if (val % 2 == 1) {
            cout << val << " = " << val / 2 << " + " << val / 2 + 1;
        } else {
            bool found = false;
            for (int start = 1; start < val; ++start) {
                int summand = start;
                int goal = start;
                while (goal < val) {
                    goal += ++summand;
                }
                if (goal == val) {
                    cout << start << "..." << summand << endl;
                    found = true;
                }
            }
            if (!found) {
                cout << "IMPOSSIBLE" << endl;
            }
        }
    }

    return 0;
}
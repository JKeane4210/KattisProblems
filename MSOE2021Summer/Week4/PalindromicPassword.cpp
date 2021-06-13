//
// Created by Jonny Keane on 6/13/21.
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
        int a;
        cin >> a;
        if (a == 100000) {
            cout << 100001 << endl;
            continue;
        }
        int left = a, right = a;
        while (true) {
            if (left % 10 != 0) {
                string forward = to_string(left);
                string backward = to_string(left);
                reverse(backward.begin(), backward.end());
                if (forward == backward) {
                    cout << left << endl;
                    break; // order of this is important
                }
            }
            if (right % 10 != 0) {
                string forward = to_string(right);
                string backward = to_string(right);
                reverse(backward.begin(), backward.end());
                if (forward == backward) {
                    cout << right << endl;
                    break;
                }
            }
            --left;
            ++right;
        }
    }

    return 0;
}
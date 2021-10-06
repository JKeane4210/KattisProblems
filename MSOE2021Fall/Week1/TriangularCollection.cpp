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

    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int side;
        cin >> side;
        s.insert(side);
    }
    vector<int> sides(s.begin(), s.end());
    int count = 0;
    for (int i = 0; i < sides.size() - 2; ++i) {
        for (int j = i + 1; j < sides.size() - 1; ++j) {
            for (int k = j + 1; k < sides.size(); ++k) {
                if (sides[i] + sides[j] > sides[k] &&
                    sides[j] + sides[k] > sides[i] &&
                    sides[i] + sides[k] > sides[j]) {
                    ++count;
                }
            }
        }
    }
    cout << count << endl; // wrong --> number of subsets

    return 0;
}
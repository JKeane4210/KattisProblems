//
// Created by Jonny Keane on 1/20/22.
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

    string s;
    cin >> s;
    long total = 0;
    for (int left = 0; left < s.size(); ++left) {
        int right = left + 1;
        set<char> seen;
        while (right < s.size() && s[right] != s[left]) {
            if (seen.find(s[right]) == seen.end()) {
                ++total;
                seen.insert(s[right]);
            }
            ++right;
        }
    }
    cout << total << endl;

    return 0;
}

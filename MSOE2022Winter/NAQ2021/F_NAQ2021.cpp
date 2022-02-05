//
// Created by Jonny Keane on 1/22/22.
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

    set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    string s;
    cin >> s;
    for (int left = 0; left < s.size() - 5; ++left) {
        for (int length = 5; length <= s.size() - left; ++length) {
            string sub = s.substr(left, length);
//            cout << sub << endl;
            set<char> chars;
            for (char c: sub) {
                chars.insert(c);
            }
            if (chars.size() >= 5 && vowels.find(sub[0]) != vowels.end()) {
                cout << sub << endl;
            }
        }
    }

    return 0;
}

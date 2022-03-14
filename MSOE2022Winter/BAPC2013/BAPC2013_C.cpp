//
// Created by Jonny Keane on 3/7/22.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

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
    string M[n];
    string D, X;
    for (int i = 0; i < n; ++i) {
        cin >> M[i];
    }
    cin >> D >> X;
    bool match_found = false;
    char decrypt[26];
    for (int i = 0; i < n; ++i) {
        if (M[i].size() != D.size()) continue;
        char poss_decrypt[26];
        set<char> used_letters;
        for (char & j : poss_decrypt) {
            j = '?';
        }
        bool possible = true;
        for (int j = 0; j < D.size(); ++j) {
            if (poss_decrypt[M[i][j] - 'a'] != '?') {
                if (poss_decrypt[M[i][j] - 'a'] != D[j]) {
                    possible = false;
                    break;
                }
            } else {
                if (used_letters.find(D[j]) == used_letters.end()) {
                    used_letters.insert(D[j]);
                    poss_decrypt[M[i][j] - 'a'] = D[j];
                } else { // if you are matching to a letter that is non-unique, not possible
                    possible = false;
                    break;
                }
            }
        }
        char missing_char = 0;
        if (used_letters.size() == 25) {
            for (char c = 'a'; c <= 'z'; ++c) {
                if (used_letters.find(c) == used_letters.end()) {
                    missing_char = c;
                    break;
                }
            }
        }
        if (missing_char != 0) {
            for (int j = 0; j < 26; ++j) {
                if (poss_decrypt[j] == '?') {
                    poss_decrypt[j] = missing_char;
                }
            }
        }
        if (possible) {
            if (!match_found) {
                match_found = true;
                for (int j = 0; j < 26; ++j) {
                    decrypt[j] = poss_decrypt[j];
                }
            } else {
//                cout << i << endl;
                for (int j = 0; j < 26; ++j) {
                    if (decrypt[j] != poss_decrypt[j]) {
//                        cout << (char)(j + 'a') << " " << decrypt[j] << " " << poss_decrypt[j] << endl;
                        decrypt[j] = '?';
                    }
                }
            }
        }
    }
    if (match_found) {
        for (auto c: X) {
            cout << decrypt[c - 'a'];
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        solve();
    }

    return 0;
}
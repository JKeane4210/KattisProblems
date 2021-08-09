//
// Created by Jonny Keane on 8/1/21.
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

    string prev;
    cin >> prev;
    int n;
    cin >> n;
    string animals[n];
    vector<string> valids;
    map<char, vector<string>> firstLetters;
    for (int i = 0; i < n; ++i) {
        string animal;
        cin >> animal;
        if (firstLetters.find(animal[0]) == firstLetters.end()) {
            firstLetters[animal[0]] = vector<string>();
        }
        firstLetters[animal[0]].emplace_back(animal);
        if (animal[0] == prev[prev.size() - 1]) {
            valids.emplace_back(animal);
        }
    }
    if (valids.empty()) {
        cout << "?" << endl;
    } else {
        string res = valids[0];
        for (const string& valid: valids) {
            if (firstLetters.find(valid[valid.size() - 1]) == firstLetters.end() ||
                    (firstLetters[valid[valid.size() - 1]].size() == 1 && valid[0] == valid[valid.size() - 1])) {
                res = valid + "!";
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
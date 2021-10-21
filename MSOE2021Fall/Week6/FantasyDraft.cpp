//
// Created by Jonny Keane on 10/12/21.
//

// naively:
// for k rounds:
//   for n teams:
//      if teams[n].empty

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

    int n, k;
    cin >> n >> k;
    vector<string> prefs[n];
    string teams[n][k];
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        prefs[i] = vector<string>(q);
        for (int j = 0; j < q; ++j) {
            cin >> prefs[i][q - 1 - j];
        }
    } // using these as stacks
    int p;
    cin >> p;
    string order[p];
    for (int i = 0; i < p; ++i) {
        cin >> order[i];
    }
    int bestInOrder = 0;
    set<string> picked;
    for (int i = 0; i < k; ++i) { // for each round
        for (int j = 0; j < n; ++j) { // for each team
            string pick;
            while (!prefs[j].empty() && picked.count(prefs[j][prefs[j].size() - 1]) != 0) {
                prefs[j].pop_back();
            }
            if (!prefs[j].empty()) {
                teams[j][i] = prefs[j][prefs[j].size() - 1];
                prefs[j].pop_back();
            } else {
                while (picked.count(order[bestInOrder]) != 0) {
                    ++bestInOrder;
                }
                teams[j][i] = order[bestInOrder++];
            }
            picked.insert(teams[j][i]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << teams[i][j] << ' ';
        }
        cout << "\n";
    }
    cout << endl;

    return 0;
}

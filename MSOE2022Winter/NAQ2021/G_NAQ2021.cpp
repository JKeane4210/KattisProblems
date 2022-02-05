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

    int c, n;
    cin >> c >> n;
    int errors[n];
    for (int i = 0; i < n; ++i) {
        cin >> errors[i];
    }
    int error_index = 0;
    vector<string> corrects;
    vector<string> incorrects;
    int curr = 1;
    while (curr <= c) {
//        cout << curr << endl;
        if (error_index == n) {
            if (c - curr > 1) {
                corrects.pb(to_string(curr) + "-" + to_string(c));
            } else {
                corrects.pb(to_string(curr++));
            }
            break;
        }
        if (errors[error_index] != 1) {
            if (errors[error_index] - curr > 1) {
                corrects.pb(to_string(curr) + "-" + to_string(errors[error_index] - 1));
            } else {
                corrects.pb(to_string(curr++));
            }
        }
        curr = errors[error_index];
        int start = errors[error_index];
        int end = errors[error_index];
        while (++curr == errors[++error_index]) {
            end = curr;
        }
        if (end - start >= 1) {
            incorrects.pb(to_string(start) + "-" + to_string(end));
        } else {
            incorrects.pb(to_string(start));
        }
        curr = end + 1;
    }
    cout << "Errors: ";
    for (int i = 0; i < incorrects.size(); ++i) {
        cout << incorrects[i];
        if (incorrects.size() == 1) continue;

        if (i < incorrects.size() - 2) {
            cout << ", ";
        } else if (i == incorrects.size() - 2) {
            cout << " and ";
        }
    }

    cout << nl << "Correct: ";
    for (int i = 0; i < corrects.size(); ++i) {
        cout << corrects[i];

        if (corrects.size() == 1) continue;
        if (i < corrects.size() - 2) {
            cout << ", ";
        } else if (i == corrects.size() - 2) {
            cout << " and ";
        }
    }
    cout << endl;


    return 0;
}
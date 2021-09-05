//
// Created by Jonny Keane on 9/3/21.
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

void solve(int i) {
    int R, P, D;
    cin >> R >> P >> D;
    double scaling_factor = 1.0 * D / P;
    string baker_100;
    double scaled_weight;
    pair<string, pair<double, double>> ingredients[R];
    for (int i = 0; i < R; ++i) {
        string ingredient;
        double weight, percentage;
        cin >> ingredient >> weight >> percentage;
        if (percentage == 100) {
            baker_100 = ingredient;
            scaled_weight = scaling_factor * weight;
        }
        ingredients[i] = make_pair(ingredient, make_pair(weight, percentage));
    }
    cout << "Recipe # " << i << endl;
    for (const auto& p: ingredients) {
        cout << p.first << " ";
        if (p.first == baker_100) {
            cout << scaled_weight << endl;
        } else {
            cout << p.second.second * scaled_weight / 100.0 << endl;
        }
    }
    cout << string(40, '-') << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(1);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve(i + 1);
    }

    return 0;
}
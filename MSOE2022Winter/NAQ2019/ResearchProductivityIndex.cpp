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

double research_index(const vector<int> & probs) {
    double expected_accepted = 0;
    for (auto p: probs) {
        expected_accepted += (double)p / 100.0;
    }
    return pow(expected_accepted, expected_accepted / probs.size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    priority_queue<int> probs;
    for (int i = 0; i < n; ++i) {
        int prob;
        cin >> prob;
        probs.push(prob);
    }
    double max_e = 0;
    vector<int> curr_probs;
    while (true) {
        curr_probs.emplace_back(probs.top());
        probs.pop();
        double e = research_index(curr_probs);
        if (e < max_e) {
            break;
        } else {
            max_e = e;
        }
        cout << max_e << endl;
    }

    return 0;
}
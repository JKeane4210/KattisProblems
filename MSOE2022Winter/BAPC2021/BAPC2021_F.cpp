//
// Created by Jonny Keane on 2/23/22.
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

pll partner(pll a, pll goal) {
    return make_pair(goal.first - a.first, goal.second - a.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if (n % 2 == 1) {
        cout << "impossible" << endl;
        return 0;
    }
    int teams = n / 2;
    long total_billiards = 0;
    long total_pool = 0;
    map<pll, int> skills;
    for (int i = 0; i < n; ++i) {
        long billiard, pool;
        cin >> billiard >> pool;
        total_billiards += billiard;
        total_pool += pool;
        skills[make_pair(billiard, pool)]++;
    }
//    cout << total_billiards << " " << total_pool << endl;
    if (total_billiards % teams != 0 || total_pool % teams != 0) {
        cout << "impossible" << endl;
        return 0;
    }
    pll goal = make_pair(total_billiards / teams, total_pool / teams);

    for (auto skill: skills) {
        if (skills[partner(skill.first, goal)] != skill.second) {
            cout << "impossible" << endl;
            return 0;
//            cout << skill.first.first << " " << skill.first.second << " " << skill.second << endl;
        }
    }
    cout << "possible" << endl;

    return 0;
}
//
// Created by Jonny Keane on 2/28/22.
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

    int n, s;
    cin >> n >> s;
    int used = 0;
    int refills = 0;
    for (int i = 0; i < n; ++i) {
        string student;
        cin >> student;
        int shots;
        if (student[student.size() - 1] == 'L') {
            shots = stoi(student.substr(0, student.size() - 1)) + 1;
        } else {
            shots = stoi(student);
        }
        if (used + shots > s) {
            used = 0;
            ++refills;
        }
        used += shots;
    }
    cout << refills << endl;

    return 0;
}
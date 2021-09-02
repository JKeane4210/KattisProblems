//
// Created by Jonny Keane on 5/8/21.
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

    map<char, int> wrongs;
    int time = 0;
    char prob;
    string res;
    int total = 0;
    int solved = 0;
    cin >> time;
    while (time != -1) {
        cin >> prob >> res;
        if (res == "right") {
            if (wrongs.find(prob) != wrongs.end()) {
                total += wrongs[prob] * 20;
            }
            total += time;
            ++solved;
        } else {
            if (wrongs.find(prob) != wrongs.end()) {
                ++wrongs[prob];
            } else {
                wrongs[prob] = 1;
            }
        }
        cin >> time;
    }
    cout << solved << " " << total << endl;

    return 0;
}
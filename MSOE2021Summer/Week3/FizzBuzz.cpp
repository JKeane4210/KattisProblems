//
// Created by Jonny Keane on 6/6/21.
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

    int X, Y, N;
    cin >> X >> Y >> N;
    for (int i = 1; i <= N; ++i) {
        if (i % X == 0 & i % Y == 0) {
            cout << "FizzBuzz" << endl;
        } else if (i % X == 0) {
            cout << "Fizz" << endl;
        } else if (i % Y == 0) {
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }
    }

    return 0;
}
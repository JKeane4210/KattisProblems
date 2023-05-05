//
// Created by keanej on 4/23/2023.
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
#define wgraph V<V<pii>>

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
    
    int c, d;
    cin >> c >> d;
    int last_fizz = -1;
    int last_buzz = -1;
    int a = -1;
    int b = -1;
    for (int i = c; i <= d; ++i) {
        string s;
        cin >> s;
        if (s == "Fizz") {
            if (last_fizz != -1) {
                a = i - last_fizz;
            }
            last_fizz = i;
        } else if (s == "Buzz") {
            if (last_buzz != -1) {
                b = i - last_buzz;
            }
            last_buzz = i;
        } else if (s == "FizzBuzz") {
            if (last_fizz != -1) {
                a = i - last_fizz;
            }
            last_fizz = i;
            if (last_buzz != -1) {
                b = i - last_buzz;
            }
            last_buzz = i;
        }
    }
    if (a != -1) {
        cout << a;
    } else if (last_fizz != -1) {
        cout << last_fizz;
    } else {
        cout << d + 1;
    }
    cout << " ";
    if (b != -1) {
        cout << b;
    } else if (last_buzz != -1) {
        cout << last_buzz;
    } else {
        cout << d + 1;
    }
    cout << endl;
    
    return 0;
}

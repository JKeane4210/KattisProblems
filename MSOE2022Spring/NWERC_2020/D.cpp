//
// Created by Jonny Keane on 3/15/22.
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

    map<long, long> squares;
    long i = 0;
    while (i * i <= 2000000000000l) {
        squares[i * i] = i;
        ++i;
    }

    int n;
    cin >> n;
    set<pll> guessed;
    while (n > 0) {
        cout << 0 << " " << 0 << endl;
        long d1;
        cin >> d1;
        if (d1 == 0) {
            --n;
            continue;
        }

        vpll guesses;
        for (long i = 0; i <= (long)ceil(sqrt(d1)); ++i) {
            if (squares.find(d1 - i * i) != squares.end()) {
                pll guess = mp(i, squares[d1 - i * i]);
                if (guessed.find(guess) == guessed.end() && guess.first <= 1000000l && guess.second <= 1000000l) {
                    guesses.pb(guess);
                }
            }
        }
        for (auto guess: guesses) {
            cout << guess.first << " " << guess.second << endl;
            guessed.insert(guess); // only add guesses when you guess them
            long d;
            cin >> d;
            if (d == 0) {
                --n;
                break;
            }
        }
    }

    return 0;
}
//
// Created by Jonny Keane on 2/28/22.
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

    const long limit = 1299709 + 1;
    bitset<limit> sieve;
    vector<int> primes;
    sieve.reset();
    for (long i = 2; i < limit; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (long j = i * i; j < limit; j += i) {
                sieve[j] = true;
            }
        }
    }
    int l, r;
    string s;
    cin >> l >> r >> s;
    int count = 0;
    for (int i = l - 1; i < r; ++i) {
        if (to_string(primes[i]).find(s) != string::npos) {
            ++count;
        }
    }
    cout << count << endl;

    return 0;
}
//
// Created by Jonny Keane on 7/10/21.
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

    const int limit = 46340;
    bitset<limit + 1> sieve;
    sieve.reset();
    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (!sieve[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = true;
            }
        }
    }

    int n;
    while (cin >> n) {
//    for (int i = -INT_MAX; i <= INT_MAX; ++i) {
//        int n = i;
//        cout << n << ": " << endl;
        if (abs(n) < 2) continue;
        multiset<int> factors;
        bool isNeg = n < 0;
        if (isNeg) {
            cout << "-1 ";
        }
        n = abs(n);

        auto it = primes.begin();
        while (n != 1 && it != primes.end()) {
            if (n % *it == 0) {
                factors.insert(*it);
                n /= *it;
            } else {
                ++it;
            }
        }

        set<int> used;
        for (int factor: factors) {
            if (used.count(factor) != 0) continue;
            used.insert(factor);
            if (factors.count(factor) > 1) {
                cout << factor << "^" << factors.count(factor) << " ";
            } else {
                cout << factor << " ";
            }
        }
        if (it == primes.end()) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}

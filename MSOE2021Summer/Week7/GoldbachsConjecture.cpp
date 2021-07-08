//
// Created by Jonny Keane on 7/5/21.
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

bitset<32000> sieve;
set<int> primes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i < 32000; ++i) {
        if (!sieve[i]) {
            primes.insert(i);
            for (int j = i * i; j < 32000; j += i) {
                sieve[j] = true;
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vector<pair<int, int>> reps;
        for (int prime: primes) {
            if (prime > x - prime) {
                break;
            }
            if (primes.count(x - prime) != 0) {
                reps.emplace_back(make_pair(prime, x - prime));
            }
        }
        cout << x << " has " << reps.size() << " representation(s)" << endl;
        for (auto rep: reps) {
            cout << rep.first << "+" << rep.second << endl;
        }
        cout << endl;
    }

    return 0;
}
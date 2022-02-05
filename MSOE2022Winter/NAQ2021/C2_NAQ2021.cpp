//
// Created by Jonny Keane on 1/22/22.
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

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<ll, ll> g(const vector<long long> & primes, int ind) {
    long p = 1;
    long q = 1;
    for (int i = 0; i <= ind; ++i) {
        p *= primes[i] - 1;
        q *= primes[i];
    }
    long long gcd_ = gcd(q, q - p);
    return make_pair((q - p) / gcd_, q / gcd_);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    const int limit = 50;
    bitset<limit + 1> sieve;
    sieve.reset();
    vector<long long> jumps;
    vector<long long> primes;
    long long prod = 1;
    long long numer = 1;
    for (int i = 2; i <= limit; ++i) {
        if (!sieve[i]) {

            if (prod < 0 || prod * i > n) {
                break;
            }
            prod *= i;
            numer *= i - 1;
            jumps.push_back(prod);
            primes.push_back(i);
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = true;
            }
        }
    }

//    for (n = 2; n < 100000; ++n) {
//        int ind = 0;
//        while (ind < jumps.size() && n >= jumps[ind]) {
//            ++ind;
//        }
//        --ind;
//        double max_ = 0;
//        pair<ll, ll> max_p = make_pair(0, 0);
//        for (int i = 0; i <= ind; ++i) {
//            auto p = g(primes, i);
//            if (1.0 * p.first / p.second > max_) {
//                max_ = 1.0 * p.first / p.second;
//                max_p = p;
//            }
//        }
        long long gc = gcd(numer, prod);
        cout << (prod - numer )/ gc<< "/" << prod / gc << endl;
//    }
//    cout << jumps[ind] << endl;
//    long long val = g(primes, ind);
//    long long gcd_ = gcd(val, jumps[ind]);
//    cout << val / gcd_ <<  "/" << jumps[ind] / gcd_ << endl;

    return 0;
}
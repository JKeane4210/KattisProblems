//
// Created by Jonny Keane on 5/31/21.
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
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

void breakdownNumber(long long num, long long den) {
    if (den != 0) {
        cout << (num / den) << " ";
        breakdownNumber(den, num % den);
    } else {
        cout << endl;
    }
}

pair<long long, long long> unMixNumber(long long* partialQuotients, long long n, long long ind) {
    if (n == 1) {
        return make_pair(partialQuotients[0], 1);
    }
    if (ind == n - 2) {
        return make_pair(partialQuotients[n - 2] * partialQuotients[n - 1] + 1, partialQuotients[n - 1]);
    } else {
        pair<long long, long long> unMixedRest = unMixNumber(partialQuotients, n, ind + 1);
        return make_pair(partialQuotients[ind] * unMixedRest.first + unMixedRest.second, unMixedRest.first);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n1, n2;
    cin >> n1 >> n2;
    long long r1[n1];
    long long r2[n2];
    for (int i = 0; i < n1; ++i) {
        cin >> r1[i];
    }
    for (int i = 0; i < n2; ++i) {
        cin >> r2[i];
    }
    pair<long long, long long> r1NumDen = unMixNumber(r1, n1, 0);
    pair<long long, long long> r2NumDen = unMixNumber(r2, n2, 0);
//    cout << r1NumDen.first << "/" << r1NumDen.second << endl;
    long long addGcd = gcd(r1NumDen.first * r2NumDen.second + r2NumDen.first * r1NumDen.second, r1NumDen.second * r2NumDen.second);
    breakdownNumber((r1NumDen.first * r2NumDen.second + r2NumDen.first * r1NumDen.second) / addGcd,
                    (r1NumDen.second * r2NumDen.second) / addGcd);
    long long subGcd = gcd(r1NumDen.first * r2NumDen.second - r2NumDen.first * r1NumDen.second, r1NumDen.second * r2NumDen.second);
    breakdownNumber((r1NumDen.first * r2NumDen.second - r2NumDen.first * r1NumDen.second) / subGcd,
                    (r1NumDen.second * r2NumDen.second) / subGcd);
    long long multGcd = gcd(r1NumDen.first * r2NumDen.first, r1NumDen.second * r2NumDen.second);
    breakdownNumber((r1NumDen.first * r2NumDen.first) / multGcd,
                    (r1NumDen.second * r2NumDen.second) / multGcd);
    long long divGcd = gcd(r1NumDen.first * r2NumDen.second, r1NumDen.second * r2NumDen.first);
    breakdownNumber((r1NumDen.first * r2NumDen.second) / divGcd,
                    (r1NumDen.second * r2NumDen.first) / divGcd);
    return 0;
}
//
// Created by Jonny Keane on 6/16/21.
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

vector<int> primes;
bitset<46341>sieve;


string playGame() {
    int M = 1;
    int N;
    cin >> N;
    string starter;
    cin >> starter;
    bool isStarter = true;
    while (M < N) {

    }
    return "tie";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    int limit = 46340;
    for (int i = 2; i <= limit; ++i) {
        if (!sieve[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = true;
            }
        }
    }
    for (int i: primes) {
        cout << i << " ";
    }
    cout << endl;
//    for (int i = 0; i < n; ++i){
//        cout << playGame() << endl;
//    }


    return 0;
}
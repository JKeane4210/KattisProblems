//
// Created by Jonny Keane on 1/19/22.
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

    int n;
    cin >> n;
    int cards[n];
    long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
//        total += cards[i];
    }
    double average = 0;
    int included = 0;
    int left = 0;
    int right = n - 1;
    bool change_made = true;
    while (change_made) {
        change_made = false;
        if ((double)(total + cards[left]) / (included + 1) >= average) {
            total += cards[left];
            ++included;
            ++left;
            change_made = true;
        } else if ((double)(total + cards[right]) / (included + 1) >= average) {
            total += cards[right];
            ++included;
            --right;
            change_made = true;
        }
        average = included == 0 ? 0 : (double)total / included;
    }
    cout.precision(10);
    cout << average << endl;

    return 0;
}

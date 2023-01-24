//
// Created by Jonny Keane on 7/8/21.
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

int powSum(int num) {
    if (num == 0) return 0;
    if (num == 1) {
        return 1;
    } else {
        return num + (num / 2);
    }
}

void ternarianWeights() {
    int x;
    cin >> x;
    int pow = 1162261467;
    vector<int> left;
    vector<int> right;
    while (x != 0) {
        // check which side of the balance you are on because always
        // want to go in the direction of bringing closer to 0

        // if adding current weight to the left pan can be matched
        // or exceeded by all remaining weights, add this weight to
        // the left pan and solve the problems towards new weight separation
        if (x < 0 && powSum(pow / 3) >= x + pow) {
            left.push_back(pow);
            x += pow;
        }
        // if current left weight + all potential remaining weights
        // can match or exceed adding this weight to the right pan,
        // add it and solve the problem towards new weight separation
        if (x > 0 && x + powSum(pow / 3) >= pow) {
            right.push_back(pow);
            x -= pow;
        }
        pow /= 3;
    }
    cout << "left pan:";
    for (int l: left) {
        cout << " " << l;
    }
    cout << endl;
    cout << "right pan:";
    for (int r: right) {
        cout << " " << r;
    }
    cout << endl << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ternarianWeights();
    }

    return 0;
}
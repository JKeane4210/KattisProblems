//
// Created by Jonny Keane on 7/6/21.
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

void ternarianWeights(int x, bitset<20> left, bitset<20> right, int size, int sizePow) {
    if (x < 0 || size == 20) return;
    if (x == 0) {
        cout << "left pan:";
        int pow = sizePow / 3;
        for (int i = 0; i < size; ++i) {
            if (left[size - 1 - i]) {
                cout << " " << pow;
            }
            pow /= 3;
        }
        cout << endl;
        cout << "right pan:";
        pow = sizePow / 3;
        for (int i = 0; i < size; ++i) {
            if (right[size - 1 - i]) {
                cout << " " << pow;
            }
            pow /= 3;
        }
        cout << endl << endl;
        return;
    }
    bitset<20> l(left);
    l[size] = true;
    bitset<20> r(right);
    r[size] = true;
    ternarianWeights(x - sizePow, bitset<20>(left), r, size + 1, sizePow * 3);
    ternarianWeights(x, bitset<20>(left), bitset<20>(right), size + 1, sizePow * 3);
    ternarianWeights(x + sizePow, l, bitset<20>(right), size + 1, sizePow * 3);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i) {
        int x;
        cin >> x;
        ternarianWeights(x, bitset<20>(), bitset<20>(), 0, 1);
    }

    return 0;
}
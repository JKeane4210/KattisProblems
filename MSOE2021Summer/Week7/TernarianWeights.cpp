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

struct Step {
public:
    bitset<20> left;
    bitset<20> right;
    int leftSum;
    int rightSum;
    int size;
    int sizePow;
    Step(bitset<20> left, bitset<20> right, int leftSum, int rightSum, int size, int sizePow) :
    left(left), right(right), leftSum(leftSum), rightSum(rightSum), size(size), sizePow(sizePow) {}
};

void ternarianWeights() {
    int x;
    cin >> x;
    queue<Step> q;
    q.push(Step(bitset<20>(), bitset<20>(), x, 0, 0, 1));
    while (true) {
        Step top = q.front();
        q.pop();
        if (top.leftSum == top.rightSum) {
            cout << "left pan:";
            int pow = top.sizePow / 3;
            for (int i = 0; i < top.size; ++i) {
                if (top.left[top.size - 1 - i]) {
                    cout << " " << pow;
                }
                pow /= 3;
            }
            cout << endl;
            cout << "right pan:";
            pow = top.sizePow / 3;
            for (int i = 0; i < top.size; ++i) {
                if (top.right[top.size - 1 - i]) {
                    cout << " " << pow;
                }
                pow /= 3;
            }
            cout << endl << endl;
            return;
        } else {
            q.push(Step(bitset<20>(top.left), bitset<20>(top.right), top.leftSum, top.rightSum, top.size + 1,
                        top.sizePow * 3));
            if (top.leftSum + top.sizePow > top.rightSum) {
                bitset<20> l(top.left);
                l[top.size] = true;
                q.push(Step(l, bitset<20>(top.right), top.leftSum + top.sizePow, top.rightSum, top.size + 1,
                            top.sizePow * 3));
            }
            bitset<20> r(top.right);
            r[top.size] = true;
            q.push(Step(bitset<20>(top.left), r, top.leftSum, top.rightSum + top.sizePow, top.size + 1,
                        top.sizePow * 3));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // greedy adding to the lesser
    // start with smallest sum greater than
    // recursive
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ternarianWeights();
    }

    return 0;
}
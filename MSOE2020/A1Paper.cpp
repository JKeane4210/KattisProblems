//
// Created by Jonny Keane on 5/8/21.
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

pair<double, double> dimensions[31]; // just for making 2-30 more intuitive

// have to make 2 of and A2
double makeAn(int* papers, int size, int index, int goal, double tape) {
    pair<double, double> currDim = dimensions[index + 2];
    int currentPaper = index + 2;
    if (index == size) {
        return -1;
    }
    if (papers[index] > 0) {
        if (currentPaper == goal) {
            return tape + currDim.first;
        } else {
            ++goal;
            --papers[index]; // need to know that this is one in front of it
            return makeAn(papers, size, index, goal, tape + something);
        }
    } else {
        return makeAn(papers, size, index + 1, goal, tape + something);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    double width = pow(2.0, -1.25);
    double height = pow(2.0, -0.75);
    for (int i = 2; i <= 30; ++i) {
//        cout << "A" << i << " " << width << " " << height << " " << width * height << endl;
        dimensions[i] = make_pair(max(width, height), min(width, height));
        if (i % 2 == 0) {
            height /= 2;
        } else {
            width /= 2;
        }
    }
    int papers[n];
    for (int i = 0; i < n; ++i) {
        cin >> papers[n];
    }

    double result = makeAn(papers, n, 0, 1, 0.0) / 100.0;
    cout << result << endl;

    return 0;
}
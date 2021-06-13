//
// Created by Jonny Keane on 6/6/21.
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

    int X1, X2;
    cin >> X1 >> X2;
    int N1;
    cin >> N1;
    int times1[N1];
    int max_ = 0;
    for (int i = 0; i < N1; ++i) {
        cin >> times1[i];
        max_ = max(max_, times1[i]);
    }
    int N2;
    cin >> N2;
    int times2[N2];
    for (int i = 0; i < N2; ++i) {
        cin >> times2[i];
        max_ = max(max_, times2[i]);
    }
    int time = 0;
    int point1 = 0;
    int point2 = 0;
    bool isMoving1 = false;
    bool isMoving2 = false;
    while (time <= max_) {
        if (isMoving1) {
            ++X1;
        }
        if (isMoving2) {
            ++X2;
        }
        ++time;
//        cout << time << " " << X1 << " " << X2 << endl;
        if (abs(X1 - X2) < 5) {
            cout << "bumper tap at time " << time << endl;
            return 0;
        }
        if (point1 < N1 && time == times1[point1]) {
            isMoving1 = !isMoving1;
            ++point1;
        }
        if (point2 < N2 && time == times2[point2]) {
            isMoving2 = !isMoving2;
            ++point2;
        }
    }
    if (((N1 & 1) == (N2 & 1)) || (X1 > X2 && isMoving1) || (X2 > X1 && isMoving2)) {
        cout << "safe and sound" << endl;
    } else {
        int collision = X1 > X2 ? X1 - 4 - X2 : X2 - 4 - X1;
        cout << "bumper tap at time " << time + collision << endl;
    }

    return 0;
}



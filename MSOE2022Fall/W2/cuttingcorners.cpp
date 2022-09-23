//
// Created by keanej on 9/17/2022.
//

#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

#define V vector
#define vi V<int>
#define vll V<ll>
#define vd V<double>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define vpii V<pii>
#define vpll V<pll>
#define graph V<vi>
#define wgraph V<V<pii>>

// loops
#define WHILE(n) while(n--)
#define FOR(a) for(ll i=0;i<a;i++)
#define FIND(a, e) find(a.begin(), a.end(), e)
#define minimum(a) *min_element(a.begin(), a.end())
#define maximum(a) *max_element(a.begin(), a.end())

#define nl '\n'

// use M_PI for PI (imported from cmath within stdc++.h)

using namespace std;

double dist(pii a, pii b) {
    return sqrt((b.second - a.second) * (b.second - a.second) + (b.first - a.first) * (b.first - a.first));
}

double angle(pii a, pii b, pii c) {
    double ab = dist(a, b);
    double bc = dist(b, c);
    double ac = dist(a, c);
    return 180.0 / M_PI * acos((ab * ab + bc * bc - ac * ac) / (2.0 * ab * bc));
}

struct point {
    point * next = nullptr;
    point * prev = nullptr;
    pii xy;
    bool in_poly = true;
};

double angle(point * p) {
    return angle(p->prev->xy, p->xy, p->next->xy);
}

point * smallest_angle(int n, point * p) {
    double sharpest_angle = 360.0;
    point * res = nullptr;
    for (int i = 0; i < n; ++i) {
        double a = angle(p);
//        cout << p->xy.first << "," << p->xy.second << ":" << a << "\t";
        if (a < sharpest_angle) {
            sharpest_angle = a;
            res = p;
        }
        p = p->next;
    }
//    cout << endl;
    return res;
}

void solve(int n) {
    point * first;
    point * prev = nullptr;
    point * curr;
    point * pts[n];
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        curr = new point();
        curr->xy = mp(x, y);
        pts[i] = curr;
        if (i == 0) {
            first = curr;
        }
        if (prev != nullptr) {
            prev -> next = curr;
            curr -> prev = prev;
        }
        prev = curr;
    }
    curr->next = first;
    first->prev = curr;
//    point * ptr = first;
//    for (int i = 0; i < 2*n; ++i) {
//        cout << ptr->xy.first << "," << ptr->xy.second << ":" << angle(ptr) << " ";
//        ptr = ptr -> next;
//    }
//    cout << endl;
    point * p = first;
    while (n > 3) {
        point * smallest = smallest_angle(n, p);
//        cout << "removing " << smallest->xy.first << " " << smallest->xy.second << endl;
        double a = angle(smallest);
        smallest->prev->next = smallest->next;
        smallest->next->prev = smallest->prev;
        p = smallest->prev;
        if (angle(smallest_angle(n - 1, p)) >= a) {
            smallest->in_poly = false;
            --n;
        } else {
            break;
        }
    }
    cout << n;
    for (auto pt : pts) {
        if (pt->in_poly) {
            cout << " " << pt->xy.first << " " << pt->xy.second;
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n != 0) {
        solve(n);
        cin >> n;
    }

    return 0;
}
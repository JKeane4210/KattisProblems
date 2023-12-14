//
// Created by keanej on 5/28/2023.
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

double EPS = 1e-6;

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

struct circle {
    int x, y, r;
};

struct point {
    int id;
    double px, py;
    point * next;
};

bool same(point a, point b) {
    return abs(a.px - b.px) < EPS && abs(a.py - b.py) < EPS;
}

bool is_covered(circle & a, circle & b) {
    if (b.r > a.r) {
        return sqrt((a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x)) + a.r <= b.r;
    }
    return false;
}

bool intersects(circle & a, circle & b) {
    return a.r + b.r >= sqrt((a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x));
}

pair<double, double> intrsct_pts(circle & a, circle & b) {
    double d = sqrt((a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x));
    double A = atan2(b.y - a.y, b.x - a.x);
    double B = acos((a.r * a.r + d * d - b.r * b.r) / (2 * a.r * d));
    return {A + B, A - B};
}

void solve(int n) {
    circle circles[n];
    for (int i = 0; i < n; ++i) {
        int x, y, r;
        cin >> x >> y >> r;
        circles[i] = {x, y, r};
    }
    vector<circle> final_circles;
    for (int i = 0; i < n; ++i) {
        bool can_add = true;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (is_covered(circles[i], circles[j])) {
                can_add = false;
                break;
            }
        }
        if (can_add) {
            final_circles.pb(circles[i]);
        }
        else {
            cout << "removing covered circle" << endl;
        }
    }
    UF uf(final_circles.size());
    for (int i = 0; i < final_circles.size(); ++i) {
        for (int j = 0; j < final_circles.size(); ++j) {
            if (uf.sameSet(i, j)) continue;
            if (intersects(final_circles[i], final_circles[j])) {
                uf.join(j, i);
            }
        }
    }
    int n_gray = 0;
    for (int i = 0; i < n; ++i) {
        if (uf.e[i] < 0) {
            n_gray++;
        }
    }
    cout << "Number of gray: " << n_gray << endl;
    int n_boundary = 0;
    int ctr = 0;
    vector<point> points;
    // get number of sets
    for (int i = 0; i < final_circles.size(); ++i) {
        vector<double> intrscts;
        // add all intersection angles between circle_i and circle_j
        for (int j = 0; j < final_circles.size(); ++j) {
            if (i == j) continue;
            if (intersects(final_circles[i], final_circles[j])) {
                pair<double, double> pts = intrsct_pts(final_circles[i], final_circles[j]);
                intrscts.pb(pts.first);
                intrscts.pb(pts.second);
                cout << i << " intersects " << j << endl;
            }
        }
        if (intrscts.empty()) {
            n_boundary++;
            cout << "no intersections " << i << endl;
            continue;
        }
        sort(intrscts.begin(), intrscts.end());
        // how do I join the arcs and count them?
        // - A - tag with the circles associated with
        //      - but then what?
        // - B - create pointers of arcs
        //      - join pointers with close points and count loops
        for (int j = 0; j < intrscts.size(); ++j) {
            double theta = (intrscts[j] + intrscts[(j + 1) % intrscts.size()]) / 2;
            double px = final_circles[i].x + final_circles[i].r * cos(theta);
            double py = final_circles[i].x + final_circles[i].r * sin(theta);
            bool in_circle = false;
            for (int k = 0; k < final_circles.size(); ++k) {
                if (i == k) continue;
                double dist = sqrt((final_circles[k].x - px) * (final_circles[k].x - px) + (final_circles[k].y - py) * (final_circles[k].y - py));
                if (dist < final_circles[k].r) {
                    in_circle = true;
                    break;
                }
            }
            if (!in_circle) {
                // join to the boundary (union find?)
                double theta_a = intrscts[j];
                double x_a = final_circles[i].x + final_circles[i].r * cos(theta_a);
                double y_a = final_circles[i].y + final_circles[i].r * sin(theta_a);
                double theta_b = intrscts[(j + 1) % intrscts.size()];
                double x_b = final_circles[i].x + final_circles[i].r * cos(theta_b);
                double y_b = final_circles[i].y + final_circles[i].r * sin(theta_b);
                cout << ctr << " " << theta_a << " " << x_a << " " << y_a << endl;
                point p_b = {ctr++, x_b, y_b, nullptr};
                cout << ctr << " " << theta_b << " " << x_b << " " << y_b << endl;
                point p_a = {ctr++, x_a, y_a, &p_b};
                points.pb(p_a);
                points.pb(p_b);
            } else {
                cout << "in circle" << endl;
            }
        }
    }
    for (int j = 0; j < points.size(); ++j) {
        for (int k = 0; k < points.size(); ++k) {
            if (j == k || !same(points[j], points[k])) continue;
            if (points[j].next == nullptr) { // if j is the end of an arc, connect it to the new arc/point
                points[j].next = &points[k];
            } else if (points[k].next == nullptr) { // if k is the end of an arc, connect it to the new arc/point
                points[k].next = &points[j];
            }
//            else {
//                cerr << points[k].id << " " << points[j].id << endl;
//                assert(false); // should not happen
//            }
        }
    }
    bool visited[points.size()];
    for (int i = 0; i < points.size(); ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < points.size(); ++i) {
        if (visited[i]) continue;
        n_boundary++;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int top = q.front(); q.pop();
            if (visited[top]) continue;
            visited[top] = true;
            q.push(points[top].next->id); // keep visiting points
        }
    }
    cout << 1 + n_boundary - n_gray << endl;
    cout << string(20, '-') << endl;
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
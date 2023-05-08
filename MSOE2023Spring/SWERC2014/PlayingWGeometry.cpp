//
// Created by keysers on 5/7/23.
//

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define V vector
#define vi V<int>
#define pii pair<int, int>
#define graph V<vi>
#define wgraph V<V<pii>>
#define nl '\n'
using namespace std;

struct edge {
    int x1, y1, x2, y2;
    edge* next;
    bool is_on_border;
    edge(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2), next(nullptr), is_on_border(false) {}
};

int index_comp_n;

void print_poly(edge* p, int npts) {
    edge* curr = p;
    for (int i = 0; i < npts; ++i) {
        if (curr->is_on_border) cout << "[";
        cout << curr->x1 << "," << curr->y1 << "->";
        cout << curr->x2 << "," << curr->y2;
        if (curr->is_on_border) cout << "]";
        cout << "\t";
        curr = curr->next;
    } cout << endl;
}

edge * read_polygon(int npts) {
    set<int> xs;
    set<int> ys;
    edge* first = nullptr;
    edge* curr = nullptr;
    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    xs.insert(x1);
    ys.insert(y1);
    for (int i = 0; i < npts - 1; ++i) {
        cin >> x2 >> y2;
        xs.insert(x2);
        ys.insert(y2);
        edge * e = new edge(x1, y1, x2, y2);
        if (curr != nullptr) {
            curr->next = e;
        }
        curr = e;
        if (first == nullptr) {
            first = e;
        }
        x1 = x2;
        y1 = y2;
    }
    curr->next = new edge(x2, y2, first->x1, first->y1);
    curr->next->next = first;
    map<int, int> x_map;
    map<int, int> y_map;
    int nx = 0;
    int ny = 0;
    for (auto v: xs) {
        x_map[v] = nx++;
    }
    index_comp_n = nx-1;
    for (auto v: ys) {
        y_map[v] = ny++;
    }
    curr = first;
    for (int i= 0; i < npts; ++i) {
        curr->x1 = x_map[curr->x1];
        curr->y1 = y_map[curr->y1];
        curr->x2 = x_map[curr->x2];
        curr->y2 = y_map[curr->y2];

        if ((curr->x1 == 0 && curr->x2 == 0) || (curr->x1 == nx-1 && curr->x2 == nx-1) ||
            (curr->y1 == 0 && curr->y2 == 0) || (curr->y1 == ny-1 && curr->y2 == ny-1)) {
            curr->is_on_border = true;
        }
        curr = curr->next;
    }
//    print_poly(first, npts);
    return first;
}

bool same(edge * pa, edge* pb, int npts) {
    edge * ca = pa;
    edge * cb = pb;
    for (int i = 0; i < npts; ++i) {
        if (ca->x1 != cb->x1 || ca->x2 != cb->x2 || ca->y1 != cb->y1 || ca->y2 != cb->y2) {
            return false;
        }
        ca = ca->next;
        cb = cb->next;
    }
    return true;
}

edge * rot90(edge * p, int npts, int n) {
    edge * res;
    edge * cp = p;
    for (int i = 0; i < npts; ++i) {
        if (cp->is_on_border) {
            res = cp;
        }
        int tmp = cp->x1;
//        cout << cp->x1 << "," << cp->y1 << "->" << n - cp->y1 << "," << cp->x1 << endl;
        cp->x1 = n - cp->y1;
        cp->y1 = tmp;
//        cout << cp->x1 << "," << cp->y1 << endl;
        // p2
        tmp = cp->x2;
        cp->x2 = n - cp->y2;
        cp->y2 = tmp;
        // advance
        cp = cp->next;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int na;
    cin >> na;
    edge * pa = read_polygon(na);
    int tmp = index_comp_n;
    int nb;
    cin >> nb;
//    cout << na <<" " << nb << " " << index_comp_n << endl;
    if (na != nb || index_comp_n != tmp) {
//        cout << "a" << endl;
        cout << "no" << endl;
        return 0;
    }
    edge * pb = read_polygon(nb);
//    cout << endl;
//    print_poly(pa, na);
//    print_poly(pb, nb);
    if (same(pa, pb, na)) {
//        cout << "b" << endl;
        cout << "yes" << endl;
        return 0;
    }
    for (int i = 0; i < 3; ++i) {
        pa = rot90(pa, na, index_comp_n);
//        cout << endl;
//        print_poly(pa, na);
//        print_poly(pb, nb);
        if (same(pa, pb, na)) {
            cout << "yes" << endl;
            return 0;
        }
    }
//    cout << "c" << endl;
    cout << "no" << endl;
    return 0;
}
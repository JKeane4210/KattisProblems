#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> nums;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    int mat[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = a[i] ^ a[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        set<int> poss;
        for (int j = 0; j < n; ++j) { // create all possible solutions
            for (int k = 0; k < n; ++k) {
                if (i == j || i == k) continue;
                poss.insert(mat[j][k]);
            }
        }
        for (int sol: poss) { // for each xor seen
            int count = 0;
            if (sol == a[i]) --count;
            count += nums.count(sol); // add how many in field of nums
            cerr << a[i]<< " " << sol << " " << count << " " << nums.count(sol) << endl;
            if ((sol == a[i] && nums.count(sol) > 1) || (sol != a[i] && nums.count(sol) > 0)) { // if there is no other solution
                cout << 1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) { // member
        for (int j = 0; j < n; ++j) { // other member
            if (i == j) continue;
            set<int> poss;
            for (int k = 0; k < n; ++k) { // creating possibiliies
                for (int l = 0; l < n; ++l) {
                    if (i == k || i == l || j == k || j == l) continue;
                    poss.insert(mat[k][l]);
                }
            }
            for (int sol: poss) {
                int count = 0;
                if (sol == a[i]) --count;
                count += nums.count(sol); // add how many in field of nums
                if (count <= 0) { // if there is no other solution
                    cout << 2 << endl;
                    return 0;
                }
            }
        }
    }
    cout << 3 << endl;
    return 0;

}


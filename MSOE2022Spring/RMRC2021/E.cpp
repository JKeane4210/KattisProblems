#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+ n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= n/2) {
            res += arr[i] / 2;
        } else {
            res += arr[i];
        }
    }
    cout << res << endl;
}
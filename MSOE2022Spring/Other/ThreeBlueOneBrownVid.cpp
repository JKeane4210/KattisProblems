#include <bits/stdc++.h>
using namespace std;
bool DEBUG = false;

/**
 * For a given n and MOD, this finds all the subsets
 * of the numbers {1 ... n} that have a sum divisible
 * by 5. This program was inspired by the video that
 * uses the roots of unity find an equation to solve
 * this same problem. The program run-time complexity
 * is O(n * MOD).
 *
 * Video: https://www.youtube.com/watch?v=bOXCLR3Wric
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 50; // subsets of numbers from {1 ... n}
    int MOD = 5; // the modulus ring that we are trying to satisfy
    // dp[i][j] represents how many subsets from {1 .. i} have a sum % 5 = j
    long dp[n + 1][MOD];
    fill(dp[0], dp[0] + (n + 1) * MOD, 0);
    dp[0][0] = 1; // for the empty set (sum = 0)
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            dp[i][(i + j) % MOD] += dp[i - 1][j]; // add the configurations if you add the ith element
            dp[i][j] += dp[i - 1][j]; // add the configurations if you don't add the ith element (same as (i - 1)th row
        }
    }
    if (DEBUG) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < 5; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << "Subsets of {1 ... " << n << "} divisible by " << MOD << ": " << dp[n][0] << endl;
    return 0;
}
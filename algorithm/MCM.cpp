#include <bits/stdc++.h>
using namespace std;

int matrixMultiplication(int n, int a[]) {
    int dp[n][n] = {{0}};
    for (int len = 2; len < n; len++) {
        for (int row = 0, col = len; row < n - len; row++, col++) {
            dp[row][col] = INT_MAX;
            for (int k = row + 1; k < col; k++) {
                dp[row][col] = min(dp[row][col], (dp[row][k] + dp[k][col] + (a[row] * a[k] * a[col])));
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    cout << matrixMultiplication(n, a) << endl;

    return 0;
}

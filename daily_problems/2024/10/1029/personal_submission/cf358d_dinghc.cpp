#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n), c(n);
    for (auto& x : a) scanf("%d", &x);
    for (auto& x : b) scanf("%d", &x);
    for (auto& x : c) scanf("%d", &x);
    vector<int> dp[2] { vector<int>(n), vector<int>(n) };
    dp[0][n - 1] = a[n - 1];
    dp[1][n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dp[0][i] = max(a[i] + dp[1][i + 1], b[i] + dp[0][i + 1]);
        dp[1][i] = max(b[i] + dp[1][i + 1], c[i] + dp[0][i + 1]);
    }
    printf("%d\n", dp[0][0]);
    return 0;
}


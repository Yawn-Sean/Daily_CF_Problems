#include <bits/stdc++.h>
using namespace std;
void solveD() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<array<int, 4>> dp(n);
    // (middle first), 123, 321, (middle last)
    dp[0][0] = a[0], dp[0][1] = b[0];
    for (int i = 1; i < n; i++) {
        int t1 = max(dp[i-1][0], dp[i-1][2]); // i after i-1
        int t2 = max(dp[i-1][1], dp[i-1][3]); // i before i-1
        dp[i][0] = a[i] + t2;
        dp[i][1] = b[i] + t2;
        dp[i][2] = b[i] + t1;
        dp[i][3] = c[i] + t1;
    }
    cout << max(dp[n-1][0], dp[n-1][2]) << '\n';
}

int main() {
    solveD();
    return 0;
}

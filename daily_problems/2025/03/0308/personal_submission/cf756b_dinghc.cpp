#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + 20;
        auto it1 = ranges::lower_bound(a, a[i] - 89);
        dp[i + 1] = min(dp[i + 1], dp[it1 - a.begin()] + 50);
        auto it2 = ranges::lower_bound(a, a[i] - 1439);
        dp[i + 1] = min(dp[i + 1], dp[it2 - a.begin()] + 120);
        printf("%d\n", dp[i + 1] - dp[i]);
    }
    return 0;
}


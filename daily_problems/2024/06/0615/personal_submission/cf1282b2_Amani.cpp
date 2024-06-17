#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ranges::sort(a);
    int ans = 0;
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        if (i >= k) {
            dp[i] = min(dp[i-1], dp[i-k]) + a[i-1];
        } else {
            dp[i] = dp[i-1] + a[i-1];
        }
        if (dp[i] <= p) {
            ans = max(i, ans);
        }
    }
    return ans;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int tot = 0;
    vector<int> arr(n);
    for (auto&x: arr) {
        cin >> x;
        tot += x;
    }
    vector<int> pre(n + 2), suf(n + 2);
    vector<int> dp(n + 2), ndp(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] - 2 * arr[i - 1];
        dp[i] = max(dp[i - 1], pre[i]);
    }

    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] - 2 * arr[i - 1];
        ndp[i] = max(ndp[i + 1], suf[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        ans = max(ans, dp[i - 1] + ndp[i]);
    }
    cout << 1ll * ans + tot << '\n';
    return 0;
}

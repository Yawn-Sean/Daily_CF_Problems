#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

void solve() {
    int n, k;
    cin >> n >> k;
    int len = n / k, ans = 1;
    vector<int> a(len), b(len), c(k+1, 1);
    for (int i = 0; i < len; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < len; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i < k+1; ++i) {
        c[i] = 10 * c[i-1];
    }
    for (int i = 0; i < len; ++i) {
        int s = (c[k] - 1) / a[i] + 1;  // 最大的k位数中a[i]的倍数
        int s0 = (c[k-1] - 1) / a[i] + 1;  // b[i]=0时，以0开头，最大的k-1位数中a[i]的倍数
        int sb = (c[k-1] * (b[i]+1) - 1) / a[i] - (c[k-1] * b[i] - 1) / a[i];
        // 以b[i]开头的最大的k位数-以b[i]开头的最小的k位数之间a[i]的倍数
        if (b[i] == 0) {
            ans *= (s - s0);
        } else {
            ans *= (s - sb);
        }
        ans %= MOD;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
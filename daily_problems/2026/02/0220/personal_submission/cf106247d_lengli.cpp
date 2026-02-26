#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    ll ans = n + 1;

    // 枚举因子（原代码枚举到 1e6）
    for (ll i = 1; i <= 1000000; i++) {
        if (n % i == 0) {
            if (i <= k)
                ans = max(ans, n + i);

            ll d = n / i;
            if (d <= k)
                ans = max(ans, n + d);
        }
    }

    cout << ans << "\n";

    return 0;
}

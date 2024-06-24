// 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/05/0531/solution/cf1671d.md
//
// 完全看不懂的贪心...
#include <iostream>
#include <algorithm>

typedef long long ll;
const ll N = 2e5;
ll t, n, x, a[N + 10];

int main() {
    scanf("%lld", &t); while (t--) {
        scanf("%lld%lld", &n, &x); for (ll i = 0; i < n; i++)
            scanf("%lld", a + i);
        ll ans = 0;
        for (ll i = 1; i < n; i++)
            ans += std::abs(a[i] - a[i - 1]);
        ans += std::min(std::min(a[0], a[n - 1]) - 1, 2 * *std::min_element(a, a + n) - 2);
        ans += std::max(std::min(x - std::max(a[0], a[n - 1]), 2 * x - 2 * *std::max_element(a, a + n)), 0ll);
        printf("%lld\n", ans);
    }
    return 0;
}

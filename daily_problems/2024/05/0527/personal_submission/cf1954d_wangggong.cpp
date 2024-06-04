#include <iostream>
#include <algorithm>

typedef long long ll;
const ll N = 5000;
const ll MOD = 998244353;
ll n, a[N + 10], U[N + 10], ans, cur_sum;

int main() {
    U[0] = 1;
    scanf("%lld", &n); for (ll i = 0; i < n; i++)
        scanf("%lld", a + i);
    std::sort(a, a + n);
    for (ll i = 0; i < n; i++) {
        for (ll j = cur_sum; j >= 0; j--) {
            ans += U[j] * std::max((j + a[i] + 1) / 2, a[i]), ans %= MOD, U[j + a[i]] += U[j], U[j + a[i]] %= MOD;
        }
        cur_sum += a[i];
    }
    printf("%lld", ans);
    return 0;
}

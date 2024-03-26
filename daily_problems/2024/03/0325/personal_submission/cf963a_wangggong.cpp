#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 9, N = 1e5;
ll n, a, ia, b, k, ans, cur;
char s[N + 10];

ll _pow(ll n, ll k) {
    ll ans = 1;
    for (; k; k >>= 1) {
        if (k & 1)
            ans = ans * n % MOD;
        n = n * n % MOD;
    }
    return ans;
}

ll _inv(ll a) {
    return _pow(a, MOD - 2);
}

int main() {
    scanf("%lld%lld%lld%lld%s", &n, &a, &b, &k, s), ia = _inv(a);
    ll da = _pow(_inv(a), k), db = _pow(b, k), ca = _pow(a, n), cb = 1;
    for (ll i = 0; i < k; i++)
        cur = (cur + (s[i] == '+' ? 1 : -1) * ca * cb % MOD + MOD) % MOD, ca = ca * ia % MOD, cb = cb * b % MOD;
    // 这样会超时, 得代等比求和公式
    /*
     * for (ll i = 0, m = (n + 1) / k; i < m; i++)
     *     ans = (ans + cur + MOD) % MOD, cur = cur * da % MOD * db % MOD;
     */
    ll m = (n + 1) / k, q = da * db % MOD;
    if (q == 1)
        ans = cur * m % MOD;
    else
        ans = cur * ((_pow(q, m) - 1 + MOD) % MOD) % MOD * _inv(q - 1) % MOD;
    printf("%lld", ans);
    return 0;
}

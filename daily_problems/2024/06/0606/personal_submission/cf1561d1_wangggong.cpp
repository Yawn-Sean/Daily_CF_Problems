#include <iostream>

typedef long long ll;
const ll N = 2e5;
ll f[N + 10], n, m, t;

int main() {
    scanf("%lld%lld", &n, &m); f[1] = 1, t = 1;
    for (ll i = 2; i <= n; i++) {
        f[i] = t;
        for (ll j = 2; j <= i; j++) {
            ll k = i / j;
            ll p = i / k;
            f[i] += f[k] * (p - j + 1) % m; f[i] %= m, j = p;
        }
        t += f[i], t %= m;
    }
    printf("%lld", f[n]);
    return 0;
}

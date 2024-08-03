#include <iostream>
#include <cstring>

typedef long long ll;
const ll N = 1000;
const ll MOD = 1e9 + 7;
ll t, n, k, f[N + 10][N + 10];

ll dfs(ll n, ll k) {
    memset(f, 0, sizeof f);
    for (ll j = 1; j <= k; j++) {
        f[0][j] = 1;
        for (ll i = 1; i <= n; i++)
            f[i][j] = (f[i - 1][j] + f[n - i][j - 1]) % MOD;
    }
    return f[n][k];
}

int main() {
    scanf("%lld", &t); while (t--)
        scanf("%lld%lld", &n, &k), printf("%lld\n", dfs(n, k));
    return 0;
}

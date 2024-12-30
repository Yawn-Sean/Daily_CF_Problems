#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 5003;
long long fac[MAXN], inv[MAXN];

void pre() {
    fac[0] = 1;  // 计算阶乘数组并取模
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[0] = inv[1] = 1;  // 计算逆元数组并取模
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = inv[i] * inv[i - 1] % MOD;
    }
}

long long combination(int n, int k) {
    if (k > n) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;  // 计算组合数并取模
}

long long dp(int x, int y) {
    long long ans = 0;
    for (int i = 0; i <= min(x, y); ++i) {
        ans = (ans + combination(x, i) * combination(y, i) % MOD * fac[i] % MOD) % MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pre();
    int a, b, c;
    cin >> a >> b >> c;
    long long ans = dp(a, b) * dp(b, c) % MOD * dp(a, c) % MOD;
    cout << ans << '\n';
    return 0;
}

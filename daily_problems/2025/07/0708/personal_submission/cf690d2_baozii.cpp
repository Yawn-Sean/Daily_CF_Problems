#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e6 + 3;

const int N = 1e6;

vector<i64> fac(N), inv(N);

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % MOD;
    inv.back() = 1;
    for (int i = 0; i < MOD - 2; i++) inv.back() = inv.back() * fac.back() % MOD;
    for (int i = N - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

i64 comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();
    int n, c;
    cin >> n >> c;
    i64 ans = 0;
    for (int i = 1; i <= n; i++) ans = (ans + comb(i + c - 1, c - 1)) % MOD;
    cout << ans;
}

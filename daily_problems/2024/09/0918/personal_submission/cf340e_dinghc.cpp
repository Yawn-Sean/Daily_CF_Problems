#include <bits/stdc++.h>

using namespace std;
using li = long long;
constexpr int N = 2'000;
constexpr int MOD = 1'000'000'007;
int factorials[N + 1];

li fact(int m) {
    if (factorials[m]) return factorials[m];
    return factorials[m] = m * fact(m - 1) % MOD;
}

li inv(int a) {
    return a <= 1 ? a : MOD - static_cast<li>(MOD / a) * inv(MOD % a) % MOD;
}

int comb(int n, int k) {
    k = min(n - k, k);
    if (k == 0) return 1;
    return (fact(n) * inv(fact(k)) % MOD) * inv(fact(n - k)) % MOD;
}

int a[N + 1];
int pos[N + 1];

int main() {
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == -1) m++;
        else pos[a[i]] = i;
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1 && pos[i] == 0) {
            k++;
        }
    }
    factorials[0] = 1;
    long long ans = fact(m);
    for (int i = 1, sgn = -1; i <= k; i++, sgn = -sgn) {
        ans = (ans + MOD + 1LL * sgn * comb(k, i) * fact(m - i) % MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}


#include <bits/stdc++.h>
#define MAXN 5000
#define MOD 998244353
using namespace std;

int a, b, c;
long long fac[MAXN + 10], ifac[MAXN + 10];

long long C(int a, int b) {
    return fac[a] * ifac[b] % MOD * ifac[a - b] % MOD;
}

long long gao(int a, int b) {
    int mn = min(a, b);
    long long ret = 0;
    for (int i = 0; i <= mn; i++) ret = (ret + C(a, i) * C(b, i) % MOD * fac[i]) % MOD;
    return ret;
}

int main() {
    scanf("%d%d%d", &a, &b, &c);
    int mx = max({a, b, c});

    fac[0] = 1;
    for (int i = 1; i <= mx; i++) fac[i] = fac[i - 1] * i % MOD;
    ifac[0] = ifac[1] = 1;
    for (int i = 2; i <= mx; i++) ifac[i] = (MOD - MOD / i) * ifac[MOD % i] % MOD;
    for (int i = 2; i <= mx; i++) ifac[i] = ifac[i - 1] * ifac[i] % MOD;

    printf("%lld\n", gao(a, b) * gao(b, c) % MOD * gao(a, c) % MOD);
    return 0;
}

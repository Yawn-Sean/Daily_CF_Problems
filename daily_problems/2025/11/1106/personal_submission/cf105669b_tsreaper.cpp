#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

char s1[MAXN + 5], s2[MAXN + 5], op[5];

long long power(long long a, long long b) {
    if (a == 0) return 0;

    long long y = 1;
    for (; b; b >>= 1) {
        if (b & 1) y = y * a % MOD;
        a = a * a % MOD;
    }
    return y;
}

long long gao(char *s, int M) {
    long long ret = 0;
    for (int i = 1; s[i]; i++) ret = (ret * 10 + s[i] - '0') % M;
    return ret;
}

int main() {
    scanf("%s%s%s", s1 + 1, op, s2 + 1);
    if (op[0] == '+') printf("%lld\n", (gao(s1, MOD) + gao(s2, MOD)) % MOD);
    else if (op[0] == '-') printf("%lld\n", (gao(s1, MOD) - gao(s2, MOD) + MOD) % MOD);
    else if (op[0] == '*') printf("%lld\n", (gao(s1, MOD) * gao(s2, MOD)) % MOD);
    else printf("%lld\n", power(gao(s1, MOD), gao(s2, MOD - 1)));
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int MOD = 1e9+7;
constexpr int N = 1e5;
char lhs[N+1], rhs[N+1];
char op;

int64 fast_pow(int64 a, int64 b, int64 m) {
    a %= m;
    if (a == 0) return 0;
    int64 res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % m;
        }
        b >>= 1;
        a = (a * a) % m;
    }
    return res;
}

int main() {
    scanf("%s %c %s", lhs, &op, rhs);
    int64 lh = 0;
    for (auto p = lhs; *p != '\0'; p++) {
        lh = (lh * 10 % MOD + (p[0] - '0')) % MOD;
    }
    int64 rh = 0;
    if (op == '^') {
        int emod = MOD - 1;
        for (auto p = rhs; *p != '\0'; p++) {
            rh = (rh * 10 % emod + (p[0] - '0')) % emod;
        }
        printf("%lld\n", fast_pow(lh, rh, MOD));
    } else {
        for (auto p = rhs; *p != '\0'; p++) {
            rh = (rh * 10 % MOD + (p[0] - '0')) % MOD;
        }
        int ans = 0;
        if (op == '+') {
            ans = (lh + rh) % MOD;
        } else if (op == '-') {
            ans = (lh + MOD - rh) % MOD;
        } else {
            ans = (lh * rh) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}


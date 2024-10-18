#include <bits/stdc++.h>
#define MOD ((int) 1e9 + 7)
using namespace std;

int main() {
    int a, b; scanf("%d%d", &a, &b);
    long long ans = 0;
    for (int m = 1; m < b; m++) {
        ans = (ans + 1LL * a * m) % MOD;
        ans = (ans + 1LL * (1 + a) * a / 2 % MOD * m % MOD * b) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>
#define MAXN 100
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
char s[MAXN + 5];
long long ans;

long long P[MAXN + 5];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;
    for (int i = 1; i <= n; i++) if (s[i] == '1') {
        long long t = P[i - 1] * P[n - i] % MOD * P[n - i] % MOD;
        ans = (ans + t) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}

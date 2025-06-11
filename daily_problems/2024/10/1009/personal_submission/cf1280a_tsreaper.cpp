#include <bits/stdc++.h>
#define MAXX ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int K;
char s[MAXX + 10];

void solve() {
    scanf("%d%s", &K, s + 1);
    long long ans = strlen(s + 1);
    for (int i = 1, n = ans; i <= K; i++) {
        ans = (ans + (s[i] - '0' - 1) * (ans - i + MOD)) % MOD;
        int lim = n;
        for (int t = 2; t <= s[i] - '0'; t++) for (int j = i + 1; n < K && j <= lim; j++) s[++n] = s[j];
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

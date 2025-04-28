#include <bits/stdc++.h>
#define MAXN 1000
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, LIM[26];
char s[MAXN + 5];

int f[MAXN + 5];
long long g[MAXN + 5];

int main() {
    scanf("%d%s", &n, s + 1);
    for (int i = 0; i < 26; i++) scanf("%d", &LIM[i]);

    for (int i = 1; i <= n; i++) {
        int msk = 0;
        for (int j = i; j > 0; j--) {
            msk |= 1 << (s[j] - 'a');
            bool ok = true;
            for (int k = 0; k < 26; k++) if ((msk >> k & 1) && i - j + 1 > LIM[k]) { ok = false; break; }
            if (ok) f[i] = j;
            else break;
        }
    }

    g[0] = 1;
    for (int i = 1; i <= n; i++) for (int j = f[i] - 1; j < i; j++) g[i] = (g[i] + g[j]) % MOD;
    printf("%lld\n", g[n]);

    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, i - f[i] + 1);
    printf("%d\n", mx);

    int t = 0;
    for (int i = n; i > 0; i = f[i] - 1) t++;
    printf("%d\n", t);
    return 0;
}

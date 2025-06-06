#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, m, K;
long long ans;

bool flag[MAXN + 5];
int f[MAXN + 5];
long long P[MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    P[0] = 1;
    for (int i = 1; i <= n; i++) P[i] = P[i - 1] * 2 % MOD;

    int l = 1, r = n;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        int det = y - x - 1;
        if (det == 0) continue;
        if (det != K) { printf("0\n"); return 0; }
        flag[x] = true;
        l = max(l, x); r = min(r, y);
    }

    for (int i = 1; i + K + 1 <= n; i++) if (!flag[i]) f[i] = 1;
    for (int i = 1; i <= n; i++) f[i] += f[i - 1];

    ans = 1;
    for (int i = r; i > l && i - K - 1 >= 1; i--)
        ans = (ans + P[f[i - 1] - f[i - K - 1]]) % MOD;
    for (int i = 1; i <= n; i++) if (flag[i]) { ans = (ans - 1 + MOD) % MOD; break; }

    printf("%lld\n", ans);
    return 0;
}

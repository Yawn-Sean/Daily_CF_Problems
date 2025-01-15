#include <bits/stdc++.h>
#define MAXPROD ((int) 5e5)
#define MOD ((int) 1e6 + 3)
using namespace std;

int n, m;
char s[MAXPROD + 5];

int f[MAXPROD + 5], g[MAXPROD + 5];

int idx(int i, int j) { return i * m + j; }

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s + i * m);

    memset(f, -1, sizeof(int) * (n * m + 5));
    memset(g, -1, sizeof(int) * (n * m + 5));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[idx(i, j)] != '.') {
        int x = s[idx(i, j)] - '0';
        int a, b;
        if (x == 1) a = 1, b = 1;
        else if (x == 2) a = 0, b = 1;
        else if (x == 3) a = 0, b = 0;
        else a = 1, b = 0;
        a ^= i & 1 ^ 1; b ^= j & 1 ^ 1;

        int t = idx(0, j);
        if (f[t] == -1 || f[t] == a) f[t] = a;
        else { printf("0\n"); return 0; }
        t = idx(i, 0);
        if (g[t] == -1 || g[t] == b) g[t] = b;
        else { printf("0\n"); return 0; }
    }

    long long ans = 1;
    if (f[0] == -1) ans *= 2;
    if (g[0] == -1) ans *= 2;
    for (int j = 1; j < m; j++) if (f[idx(0, j)] == -1) ans = ans * 2 % MOD;
    for (int i = 1; i < n; i++) if (g[idx(i, 0)] == -1) ans = ans * 2 % MOD;
    printf("%lld\n", ans);
    return 0;
}

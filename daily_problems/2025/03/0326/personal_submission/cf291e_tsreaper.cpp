#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXS ((int) 3e5)
#define MOD ((long long) 1e18 + 9)
#define BASE 233
using namespace std;

int n, m, len, ans, A[MAXN + 5], B[MAXN + 5];
char s[MAXS + 5], goal[MAXS + 5];

vector<int> e[MAXN + 5];
__int128 H, P[MAXS + 5], f[MAXS + 5];
int ptr;

void dfs(int sn) {
    for (int i = 0; i < B[sn]; i++) {
        ptr++;
        f[ptr] = (f[ptr - 1] * BASE + s[A[sn] + i]) % MOD;
        if (ptr >= len) {
            __int128 h = (f[ptr] - f[ptr - len] * P[len] % MOD + MOD) % MOD;
            if (h == H) ans++;
        }
    }
    for (int fn : e[sn]) dfs(fn);
    ptr -= B[sn];
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d%s", &x, s + m + 1);
        e[x].push_back(i);
        A[i] = m + 1;
        B[i] = strlen(s + m + 1);
        m += B[i];
    }
    scanf("%s", goal + 1);
    len = strlen(goal + 1);

    P[0] = 1;
    for (int i = 1; i <= len; i++) P[i] = P[i - 1] * BASE % MOD;
    for (int i = 1; i <= len; i++) H = (H * BASE + goal[i]) % MOD;
    dfs(1);
    printf("%d\n", ans);
    return 0;
}

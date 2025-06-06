#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, ans, A[MAXN + 5];

vector<int> e[MAXN + 5];
int f[MAXN + 5];

int dp(int sn) {
    if (f[sn] >= 0) return f[sn];
    f[sn] = A[sn];
    if (A[sn]) {
        for (int fn : e[sn]) {
            if (A[fn]) f[sn] = max(f[sn], dp(fn));
            else f[sn] = max(f[sn], dp(fn) + 1);
        }
    } else {
        for (int fn : e[sn]) f[sn] = max(f[sn], dp(fn));
    }
    return f[sn];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x++; y++;
        e[x].push_back(y);
    }

    memset(f, -1, sizeof(int) * (n + 3));
    ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp(i));
    printf("%d\n", ans);
    return 0;
}

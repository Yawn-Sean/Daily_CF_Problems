#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, ans;
char MAP[MAXN + 5][MAXN + 5];

int f[MAXN * MAXN + 5], g[MAXN * MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    for (int j = 1; j <= n; j++) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) cnt += MAP[i][j] - '0';
        for (int i = 1; i <= n; i++) if (MAP[i][j] == '1')
            for (int ii = i + 1; ii <= n; ii++) if (MAP[ii][j] == '1') {
                int idx = (i - 1) * n + ii - 1;
                f[idx]++;
                g[idx] = max(g[idx], cnt);
            }
        if (cnt) ans = max(ans, 1);
    }

    for (int i = 0; i < n * n; i++) ans = max(ans, min(f[i], g[i]));
    printf("%d\n", ans);
    return 0;
}

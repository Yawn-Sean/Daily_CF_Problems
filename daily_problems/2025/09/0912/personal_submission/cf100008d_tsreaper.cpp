#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, K, L, ans;
int f[MAXN + 5][MAXN + 5];

void solve() {
    scanf("%d%d%d", &n, &K, &L);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] = 0;
    for (int i = 1; i <= K; i++) {
        int x, y; scanf("%d%d", &x, &y);
        f[x][y] = 1;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] += f[i][j - 1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) f[i][j] += f[i - 1][j];

    ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        for (int k = ans + 1; k <= i && k <= j; k++) {
            int t = f[i][j] - f[i - k][j] - f[i][j - k] + f[i - k][j - k];
            if (t > L) break;
            ans = k;
        }
    }
    printf("%d\n", ans * ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

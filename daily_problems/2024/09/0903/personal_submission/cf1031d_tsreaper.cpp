#include <bits/stdc++.h>
#define MAXN 2000
#define INF ((int) 1e9)
using namespace std;

int n, K;
char MAP[MAXN + 5][MAXN + 5], ans[MAXN * 2 + 5];

int f[MAXN + 5][MAXN + 5];
bool vis[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 0; i < n; i++) scanf("%s", MAP[i]);

    f[0][0] = (MAP[0][0] == 'a' ? 1 : 0);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i + j > 0) {
        f[i][j] = -INF;
        if (i > 0) f[i][j] = max(f[i][j], f[i - 1][j]);
        if (j > 0) f[i][j] = max(f[i][j], f[i][j - 1]);
        if (MAP[i][j] == 'a') f[i][j]++;
    }

    int mx = 0;
    if (K == 0 && MAP[0][0] != 'a') {
        vis[0][0] = true;
        ans[0] = MAP[0][0];
    } else {
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            if (i + j + 1 - f[i][j] <= K) mx = max(mx, i + j);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
            if (i + j == mx && i + j + 1 - f[i][j] <= K) vis[i][j] = true;
        for (int i = 0; i <= mx; i++) ans[i] = 'a';
    }

    for (int p = mx; p < n * 2 - 2; p++) {
        char c = 'z';
        for (int i = 0; i < n; i++) {
            int j = p - i;
            if (j < 0 || j >= n || !vis[i][j]) continue;
            if (j + 1 < n) c = min(c, MAP[i][j + 1]);
            if (i + 1 < n) c = min(c, MAP[i + 1][j]);
        }
        ans[p + 1] = c;
        for (int i = 0; i < n; i++) {
            int j = p - i;
            if (j < 0 || j >= n || !vis[i][j]) continue;
            if (j + 1 < n && MAP[i][j + 1] == c) vis[i][j + 1] = true;
            if (i + 1 < n && MAP[i + 1][j] == c) vis[i + 1][j] = true;
        }
    }

    printf("%s\n", ans);
    return 0;
}

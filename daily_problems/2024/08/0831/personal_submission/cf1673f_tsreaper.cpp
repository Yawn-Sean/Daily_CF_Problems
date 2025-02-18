#include <bits/stdc++.h>
#define MAXN 32
using namespace std;

int n, q;

int f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5], h[MAXN + 5][MAXN + 5];

void gao1(int l, int r, int p) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    for (int j = 1; j <= n; j++) f[mid][j] = 1 << p;
    gao1(l, mid - 1, p - 2); gao1(mid + 1, r, p - 2);
}

void gao2(int l, int r, int p) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    for (int i = 1; i <= n; i++) g[i][mid] = 1 << p;
    gao2(l, mid - 1, p - 2); gao2(mid + 1, r, p - 2);
}

int main() {
    scanf("%d%d", &n, &q);

    gao1(1, n - 1, __lg(n - 1) * 2);
    gao2(1, n - 1, __lg(n - 1) * 2 + 1);
    for (int i = 1; i < n; i++) h[i + 1][1] = h[i][1] ^ f[i][1];
    for (int i = 1; i <= n; i++) for (int j = 1; j < n; j++) h[i][j + 1] = h[i][j] ^ g[i][j];

    for (int i = 1; i <= n; i++) for (int j = 1; j < n; j++) printf("%d%c", g[i][j], "\n "[j + 1 < n]);
    for (int i = 1; i < n; i++) for (int j = 1; j <= n; j++) printf("%d%c", f[i][j], "\n "[j < n]);
    fflush(stdout);

    int r = 1, c = 1;
    while (q--) {
        int x; scanf("%d", &x);
        auto gao = [&]() {
            for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if ((h[r][c] ^ h[i][j]) == x) {
                printf("%d %d\n", i, j); fflush(stdout);
                r = i; c = j;
                return;
            }
        };
        gao();
    }
    return 0;
}

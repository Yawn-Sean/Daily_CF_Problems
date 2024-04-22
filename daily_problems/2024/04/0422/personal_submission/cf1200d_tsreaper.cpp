#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, K;
char MAP[MAXN + 10][MAXN + 10];

int d1[MAXN + 10], d2[MAXN + 10][MAXN + 10];

void gao(int u, int d, int l, int r) {
    d2[u][l]++; d2[d + 1][l]--;
    d2[u][r + 1]--; d2[d + 1][r + 1]++;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);

    int base = 0;

    for (int i = 1; i <= n; i++) {
        int L = 1e9, R = -1e9;
        for (int j = 1; j <= n; j++) if (MAP[i][j] == 'B')
            L = min(L, j), R = max(R, j);
        if (L > R) base++;
        else {
            int l = max(1, R - K + 1), r = min(n - K + 1, L);
            if (l <= r) {
                int u = max(1, i - K + 1), d = min(n - K + 1, i);
                gao(u, d, l, r);
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        int U = 1e9, D = -1e9;
        for (int i = 1; i <= n; i++) if (MAP[i][j] == 'B')
            U = min(U, i), D = max(D, i);
        if (U > D) base++;
        else {
            int u = max(1, D - K + 1), d = min(n - K + 1, U);
            if (u <= d) {
                int l = max(1, j - K + 1), r = min(n - K + 1, j);
                gao(u, d, l, r);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i + K - 1 <= n; i++) {
        for (int j = 1; j <= n; j++) d1[j] += d2[i][j];
        int now = 0;
        for (int j = 1; j <= n; j++) now += d1[j], ans = max(ans, base + now);
    }
    printf("%d\n", ans);
    return 0;
}

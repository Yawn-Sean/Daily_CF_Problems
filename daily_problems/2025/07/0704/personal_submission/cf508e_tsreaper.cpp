#include <bits/stdc++.h>
#define MAXN 600
using namespace std;
typedef pair<int, int> pii;

int n, L[MAXN + 5], R[MAXN + 5];
char ans[MAXN * 2 + 5];

int f[MAXN + 5][MAXN + 5];

void gao(int i, int j, int l, int r) {
    if (f[i][j] == 0) {
        ans[l] = '(';
        ans[r] = ')';
        if (i == j) return;
        gao(i + 1, j, l + 1, r - 1);
    } else {
        int mid = l + (f[i][j] - i + 1) * 2;
        gao(i, f[i][j], l, mid - 1);
        gao(f[i][j] + 1, j, mid, r);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &L[i], &R[i]);

    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) f[i][j] = -1;
    for (int i = 1; i <= n; i++) if (L[i] == 1) f[i][i] = 0;
    for (int len = 2; len <= n; len++) for (int i = 1, j = len; j <= n; i++, j++) {
        int det = (j - i) * 2 + 1;
        if (L[i] <= det && det <= R[i] && f[i + 1][j] >= 0) f[i][j] = 0;
        for (int k = L[i] / 2 * 2 + 1; k <= R[i]; k++) {
            int mid = i + k / 2;
            if (mid + 1 > j) break;
            if (f[i][mid] >= 0 && f[mid + 1][j] >= 0) f[i][j] = mid;
        }
    }

    if (f[1][n] < 0) { printf("IMPOSSIBLE\n"); return 0; }
    gao(1, n, 1, n * 2);
    printf("%s\n", ans + 1);
    return 0;
}

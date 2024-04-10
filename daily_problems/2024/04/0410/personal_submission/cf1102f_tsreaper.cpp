#include <bits/stdc++.h>
#define MAXN 16
#define MAXM ((int) 1e4)
#define INF ((int) 1e9)
using namespace std;

int n, m, ans, A[MAXN][MAXM];

int f[1 << MAXN][MAXN], g[MAXN][MAXN];

int solve(int S) {
    for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) f[i][j] = 0;
    f[1 << S][S] = INF;
    for (int i = 1; i < (1 << n); i++) if (i != (1 << S)) for (int j = 0; j < n; j++) if (i >> j & 1) {
        int ii = i ^ (1 << j);
        for (int jj = 0; jj < n; jj++) f[i][j] = max(f[i][j], min(f[ii][jj], g[j][jj]));
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        int t = INF;
        for (int j = 1; j < m; j++) t = min(t, abs(A[S][j] - A[i][j - 1]));
        ret = max(ret, min(f[(1 << n) - 1][i], t));
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &A[i][j]);

    for (int i = 0; i < n; i++) for (int ii = 0; ii < n; ii++) if (i != ii) {
        int t = INF;
        for (int j = 0; j < m; j++) t = min(t, abs(A[i][j] - A[ii][j]));
        g[i][ii] = t;
    }

    for (int i = 0; i < n; i++) ans = max(ans, solve(i));
    printf("%d\n", ans);
    return 0;
}

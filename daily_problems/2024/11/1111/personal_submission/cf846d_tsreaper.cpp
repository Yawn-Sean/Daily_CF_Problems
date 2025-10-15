#include <bits/stdc++.h>
#define MAXN 500
#define INF ((int) 2e9)
using namespace std;

int n, m, K, q, A[MAXN + 5][MAXN + 5];

int f[MAXN + 5][MAXN + 5];

int calc(int lim) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (A[i][j] > lim) { f[i][j] = 0; continue; }
        f[i][j] = min({f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]}) + 1;
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) ret = max(ret, f[i][j]);
    return ret;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &K, &q);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) A[i][j] = INF;
    for (int i = 1; i <= q; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        A[x][y] = z;
    }

    if (calc(1e9) < K) { printf("-1\n"); return 0; }
    int head = 0, tail = 1e9;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (calc(mid) >= K) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}

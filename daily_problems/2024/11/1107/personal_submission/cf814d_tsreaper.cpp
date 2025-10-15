#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef long double ldb;

int n, X[MAXN + 10], Y[MAXN + 10], R[MAXN + 10];
ldb ans;

vector<int> e[MAXN + 10];
int deg[MAXN + 10];
ldb PI = acos(-1), f[MAXN + 10][2][2];

long long dis2(int i, int j) {
    return 1LL * (X[i] - X[j]) * (X[i] - X[j]) + 1LL * (Y[i] - Y[j]) * (Y[i] - Y[j]);
}

void dp(int sn) {
    ldb area = PI * R[sn] * R[sn];
    if (e[sn].empty()) {
        f[sn][0][0] = -area;
        f[sn][0][1] = f[sn][1][0] = area;
        f[sn][1][1] = -1e300;
        return;
    }

    ldb g[2][2] = {0};
    for (int fn : e[sn]) {
        dp(fn);
        for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) g[j][k] += f[fn][j][k];
    }

    for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
        f[sn][j][k] = max(
            g[j ^ 1][k] + (j == 1 ? 1 : -1) * area,
            g[j][k ^ 1] + (k == 1 ? 1 : -1) * area
        );
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &X[i], &Y[i], &R[i]);

    for (int i = 1; i <= n; i++) {
        int best = -1;
        for (int j = 1; j <= n; j++) if (R[j] > R[i] && dis2(i, j) <= 1LL * (R[j] - R[i]) * (R[j] - R[i])) {
            if (best == -1 || R[best] > R[j]) best = j;
        }
        if (best > 0) e[best].push_back(i), deg[i]++;
    }

    for (int i = 1; i <= n; i++) if (deg[i] == 0) {
        dp(i);
        ans += max(f[i][1][0], f[i][1][1]);
    }
    printf("%.12Lf\n", ans);
    return 0;
}

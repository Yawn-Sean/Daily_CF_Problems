#include <bits/stdc++.h>
#define MAXN 200
using namespace std;
typedef long double db;
typedef pair<int, int> pii;

int n, L, K;
db ans;
pii A[MAXN + 5];

db f[2][MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &L, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].second);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i].first);
    sort(A + 1, A + n + 1, greater<pii>());

    K = min(n, K);
    if (L > n) { printf("0\n"); return 0; }

    f[1][0][K] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) for (int k = 0; k <= n; k++) f[i & 1 ^ 1][j][k] = 0;
        for (int j = 0; j <= n; j++) for (int k = 0; k <= n; k++) {
            f[i & 1 ^ 1][j][k] += f[i & 1][j][k] * (100 - A[i].second) / 100;
            int kk = min(n, k + A[i].first);
            if (kk >= 0) f[i & 1 ^ 1][j + 1][kk] += f[i & 1][j][k] * A[i].second / 100;
        }
    }

    for (int j = L; j <= n; j++) for (int k = 0; k <= n; k++) ans += f[n & 1 ^ 1][j][k];
    printf("%.12Lf\n", ans);
    return 0;
}

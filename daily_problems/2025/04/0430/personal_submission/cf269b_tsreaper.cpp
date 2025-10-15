#include <bits/stdc++.h>
#define MAXN 5000
#define INF ((int) 1e9)
using namespace std;
typedef pair<double, int> pdi;

int n, m;
pdi A[MAXN + 5];

int f[2][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d%lf", &A[i].second, &A[i].first);
    sort(A + 1, A + n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) f[i & 1][j] = INF;
        for (int j = 0; j <= m; j++) f[i & 1][j] = min(f[i & 1][j], f[i & 1 ^ 1][j] + 1);
        f[i & 1][A[i].second] = min(f[i & 1][A[i].second], f[i & 1 ^ 1][A[i].second]);
        for (int j = 1; j <= m; j++) f[i & 1][j] = min(f[i & 1][j], f[i & 1][j - 1]);
    }
    printf("%d\n", f[n & 1][m]);
    return 0;
}

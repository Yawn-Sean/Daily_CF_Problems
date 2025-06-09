#include <bits/stdc++.h>
#define MAXN 500
#define INF ((int) 1e9)
using namespace std;

int n, A[MAXN + 5];
int f[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        A[x] = i;
    }

    for (int i = n; i > 0; i--) for (int j = i + 1; j <= n; j++) {
        f[i][j] = INF;
        for (int k = i + 1; k <= j; k++) f[i][j] = min(f[i][j], f[i][k - 1] + f[k][j] + abs(A[k] - A[i]));
    }
    printf("%d\n", f[1][n]);
    return 0;
}

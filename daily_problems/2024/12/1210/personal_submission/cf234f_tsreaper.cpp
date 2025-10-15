#include <bits/stdc++.h>
#define MAXN 2000
#define MAXX ((int) 4e4)
#define INF ((int) 1e9)
using namespace std;

int n, X, Y, ans, A[MAXN + 5];

int f[2][2][MAXX + 5];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 0; i <= X; i++) f[0][0][i] = f[0][1][i] = INF;
    f[0][0][0] = f[0][1][0] = 0;
    int sm = 0;
    for (int i = 1; i <= n; i++) {
        sm += A[i];
        for (int j = 0; j <= X; j++) f[i & 1][0][j] = f[i & 1][1][j] = INF;
        for (int j = 0; j <= X; j++) if (sm - j <= Y) {
            if (j >= A[i]) f[i & 1][0][j] = min(f[i & 1 ^ 1][0][j - A[i]], f[i & 1 ^ 1][1][j - A[i]] + min(A[i - 1], A[i]));
            f[i & 1][1][j] = min(f[i & 1 ^ 1][0][j] + min(A[i - 1], A[i]), f[i & 1 ^ 1][1][j]);
        }
    }

    ans = INF;
    for (int j = 0; j <= X; j++) ans = min({ans, f[n & 1][0][j], f[n & 1][1][j]});
    printf("%d\n", ans < INF ? ans : -1);
    return 0;
}

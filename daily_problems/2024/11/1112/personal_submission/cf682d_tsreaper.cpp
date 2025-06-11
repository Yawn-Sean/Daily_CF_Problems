#include <bits/stdc++.h>
#define MAXN 1000
#define MAXK 10
#define INF ((int) 1e9)
using namespace std;

int n, m, K;
char s1[MAXN + 5], s2[MAXN + 5];

int f[MAXN + 5][MAXN + 5][MAXK + 1][2];

void update(int &a, int b) { a = max(a, b); }

int main() {
    scanf("%d%d%d%s%s", &n, &m, &K, s1 + 1, s2 + 1);
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k <= K; k++)
        f[i][j][k][0] = f[i][j][k][1] = -INF;
    f[0][0][0][0] = 0;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k <= K; k++) {
        if (i < n && j < m) {
            if (s1[i + 1] == s2[j + 1]) {
                if (k < K) {
                    update(f[i + 1][j + 1][k + 1][1], f[i][j][k][0] + 1);
                    update(f[i + 1][j + 1][k + 1][1], f[i][j][k][1] + 1);
                }
                update(f[i + 1][j + 1][k][1], f[i][j][k][1] + 1);
            }
            update(f[i + 1][j + 1][k][0], f[i][j][k][0]);
            update(f[i + 1][j + 1][k][0], f[i][j][k][1]);
        }
        if (i < n) {
            update(f[i + 1][j][k][0], f[i][j][k][0]);
            update(f[i + 1][j][k][0], f[i][j][k][1]);
        }
        if (j < m) {
            update(f[i][j + 1][k][0], f[i][j][k][0]);
            update(f[i][j + 1][k][0], f[i][j][k][1]);
        }
    }
    printf("%d\n", max(f[n][m][K][0], f[n][m][K][1]));
    return 0;
}

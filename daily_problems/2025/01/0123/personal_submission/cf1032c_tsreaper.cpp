#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM 5
using namespace std;

int n, A[MAXN + 5], ans[MAXN + 5];

int f[MAXN + 5][MAXM + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 2; i <= n; i++) for (int j = 0; j < MAXM; j++) f[i][j] = -1;
    for (int i = 2; i <= n; i++) for (int j = 0; j < MAXM; j++)
        for (int jj = 0; jj < MAXM; jj++) if (f[i - 1][jj] >= 0 && j != jj) {
            if (A[i - 1] < A[i] && jj < j) { f[i][j] = jj; break; }
            if (A[i - 1] > A[i] && jj > j) { f[i][j] = jj; break; }
            if (A[i - 1] == A[i]) { f[i][j] = jj; break; }
        }
    
    for (int j = 0; j < MAXM; j++) if (f[n][j] >= 0) {
        for (int i = n; i > 0; i--) {
            ans[i] = j + 1;
            j = f[i][j];
        }
        for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
        return 0;
    }
    printf("-1\n");
    return 0;
}

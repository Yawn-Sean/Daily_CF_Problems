#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, A[MAXN + 10];

int f[MAXN + 10][5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - 1]);
            if (j % 2 == A[i] % 2) f[i][j]++;
        }
    }
    int ans = 0;
    for (int j = 1; j <= 4; j++) ans = max(ans, f[n][j]);
    printf("%d\n", ans);
    return 0;
}

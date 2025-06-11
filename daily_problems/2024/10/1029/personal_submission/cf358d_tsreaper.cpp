#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;

int n, ans, A[MAXN + 10], B[MAXN + 10], C[MAXN + 10];

int f[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &C[i]);

    for (int i = 1; i <= n; i++) {
        int smB = 0;
        for (int j = 1; j < i; j++) smB += B[j];
        f[i] = A[i] + smB;
        int g[2] = {B[i - 1], C[i - 1]};
        for (int j = i - 2; j > 0; j--) {
            f[i] = max(f[i], f[j] + A[i] + g[1]);
            g[1] = max(g[0] + C[j], g[1] + B[j]);
            g[0] += B[j];
        }
        smB = 0;
        for (int j = i + 1; j <= n; j++) smB += B[j];
        ans = max(ans, f[i] + smB);
    }
    printf("%d\n", ans);
    return 0;
}

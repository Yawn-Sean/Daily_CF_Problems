#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef long double db;

int n, A[MAXN + 5];
long long ans, B[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    ans = 1e18;
    for (int p = 0; p < 2; p++) {
        for (int i = 1; i <= n; i++) B[i] = A[i] - A[i - 1];
        long long now = 0;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == p) {
                if (B[i] <= 0) {
                    long long det = 1 - B[i];
                    B[i] += det;
                    B[i + 1] -= det;
                    now += det;
                }
            } else {
                if (B[i] >= 0) {
                    long long det = B[i] + 1;
                    B[i] -= det;
                    B[i + 1] += det;
                    now += det;
                }
            }
        }
        ans = min(ans, now);
    }
    printf("%lld\n", ans);
    return 0;
}

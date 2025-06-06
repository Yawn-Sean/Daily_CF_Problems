#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5], ans[MAXN + 5];

int L[MAXN + 5], R[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &A[i], &B[i]);

    L[1] = A[1];
    R[1] = A[1] + B[1];
    for (int i = 2; i <= n; i++) {
        L[i] = max({0, L[i - 1] - 1, A[i]});
        R[i] = min(R[i - 1] + 1, A[i] + B[i]);
        if (L[i] > R[i]) { printf("-1\n"); return 0; }
    }

    ans[n] = R[n];
    for (int i = n - 1; i > 0; i--) ans[i] = min(R[i], ans[i + 1] + 1);
    long long sm = 0;
    for (int i = 1; i <= n; i++) sm += ans[i] - A[i];
    printf("%lld\n", sm);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}

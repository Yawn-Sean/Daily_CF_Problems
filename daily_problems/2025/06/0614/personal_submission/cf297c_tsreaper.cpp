#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[MAXN + 5], B[MAXN + 5], C[MAXN + 5], ans[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &A[i]), B[i] = i;
    sort(B, B + n, [&](int x, int y) {
        return A[x] < A[y];
    });

    m = (n + 2) / 3;
    for (int i = 0; i < m && i < n; i++) {
        int idx = B[i];
        ans[idx] = A[idx] - i;
    }
    for (int i = m; i < m * 2 && i < n; i++) {
        int idx = B[i];
        ans[idx] = i;
    }
    for (int i = m * 2; i < m * 3 && i < n; i++) {
        int idx = B[i];
        ans[idx] = m * 3 - 1 - i;
    }
    
    printf("YES\n");
    for (int i = 0; i < n; i++) printf("%d%c", ans[i], "\n "[i + 1 < n]);
    for (int i = 0; i < n; i++) printf("%d%c", A[i] - ans[i], "\n "[i + 1 < n]);
    return 0;
}

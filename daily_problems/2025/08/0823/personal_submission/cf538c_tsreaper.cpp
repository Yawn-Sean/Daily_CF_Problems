#include <bits/stdc++.h>
#define MAXM ((int) 1e5)
using namespace std;

int n, m, ans, A[MAXM + 5], B[MAXM + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &A[i], &B[i]);
    ans = max(B[1] + A[1] - 1, B[m] + n - A[m]);
    for (int i = 1; i < m; i++) {
        int x = A[i + 1] - A[i], y = abs(B[i + 1] - B[i]);
        if (x < y) { printf("IMPOSSIBLE\n"); return 0; }
        ans = max(ans, max(B[i], B[i + 1]) + (x - y) / 2);
    }
    printf("%d\n", ans);
    return 0;
}

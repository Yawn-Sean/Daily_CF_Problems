#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, ans, A[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    if (n == 1 || n % 2 == 0) { printf("-1\n"); return 0; }

    for (int i = n / 2; i > 0; i--) {
        int t = max(A[i * 2], A[i * 2 + 1]);
        ans += t;
        A[i] = max(0, A[i] - t);
        A[i * 2] = max(0, A[i * 2] - t);
        A[i * 2 + 1] = max(0, A[i * 2 + 1] - t);
    }
    ans += A[1];
    printf("%d\n", ans);
    return 0;
}

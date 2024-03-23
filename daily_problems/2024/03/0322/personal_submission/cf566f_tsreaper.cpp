#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MAXX ((int) 1e6)
using namespace std;

int n, ans, A[MAXN + 10];

int f[MAXX + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) {
        f[A[i]] = max(f[A[i]], 1);
        ans = max(ans, f[A[i]]);
        for (int j = A[i] * 2; j <= A[n]; j += A[i]) f[j] = max(f[j], f[A[i]] + 1);
    }
    printf("%d\n", ans);
    return 0;
}

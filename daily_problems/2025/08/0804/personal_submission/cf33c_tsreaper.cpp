#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];
long long f[MAXN + 5][3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    f[1][0] = f[1][2] = -A[1];
    f[1][1] = A[1];
    for (int i = 2; i <= n; i++) {
        f[i][0] = f[i - 1][0] - A[i];
        f[i][1] = max(f[i - 1][0], f[i - 1][1]) + A[i];
        f[i][2] = max(f[i - 1][1], f[i - 1][2]) - A[i];
    }

    printf("%lld\n", max({f[n][0], f[n][1], f[n][2]}));
    return 0;
}

#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;

int f[MAXN + 5];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        f[i] = max(f[i - 1], A[i]);
    }

    for (int i = n, t = 0; i > 0; i--) {
        if (A[i] > f[i - 1]) t += A[i] - f[i - 1];
        ans += f[i - 1] + t - A[i];
        t = max(0, t - 1);
    }
    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q, A[MAXN + 10];
long long ans[MAXN + 10];

long long f[MAXN + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + A[i];
    for (int i = 1; i < n; i++)
        for (long long j = n - 1, k = 1, len = i; j > 0; j -= len, k++, len *= i)
            ans[i] += (f[j] - f[max(j - len, 0LL)]) * k;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x; scanf("%d", &x);
        printf("%lld%c", ans[min(x, n - 1)], "\n "[i < q]);
    }
    return 0;
}

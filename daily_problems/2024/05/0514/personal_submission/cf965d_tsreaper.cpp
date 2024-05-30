#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, K;
long long A[MAXN + 10];

long long f[MAXN + 10];

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i < n; i++) scanf("%lld", &A[i]);
    A[n] = 1e18;

    for (int i = 1; i <= K; i++) f[i] = A[i];
    for (int i = K + 1, j = 1; i <= n; i++) {
        j = max(j, i - K);
        while (j < i && f[i] < A[i]) {
            long long mn = min(f[j], A[i] - f[i]);
            f[j] -= mn;
            f[i] += mn;
            if (f[j] == 0) j++;
        }
    }

    printf("%lld\n", f[n]);
    return 0;
}

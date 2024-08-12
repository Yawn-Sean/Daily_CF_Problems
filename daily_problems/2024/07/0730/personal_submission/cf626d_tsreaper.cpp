#include <bits/stdc++.h>
#define MAXN 2000
#define MAXA 5000
using namespace std;

int n, A[MAXN + 10];

long long f[MAXA + 10], g[MAXA + 10];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
        int det = abs(A[i] - A[j]);
        if (det <= MAXA) f[det]++;
    }

    for (int i = 1; i <= MAXA; i++) for (int j = 1; i + j <= MAXA; j++)
        g[i + j] += f[i] * f[j];
    for (int i = 1; i <= MAXA; i++) g[i] += g[i - 1];

    long long cnt = 0;
    for (int i = 1; i <= MAXA; i++) cnt += f[i] * g[i - 1];
    long long tot = 1;
    for (int i = 1; i <= 3; i++) tot *= n * (n - 1) / 2;
    printf("%.12f\n", 1.0 * cnt / tot);
    return 0;
}

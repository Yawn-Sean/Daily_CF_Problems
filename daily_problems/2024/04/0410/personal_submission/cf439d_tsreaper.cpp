#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[MAXN + 10], B[MAXN + 10];
long long ans;

long long f[MAXN + 10], g[MAXN + 10];

long long gao1(int lim) {
    int head = 0, tail = n;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (A[mid] < lim) head = mid;
        else tail = mid - 1;
    }
    return 1LL * head * lim - f[head];
}

long long gao2(int lim) {
    int head = 0, tail = m;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (B[mid] <= lim) head = mid;
        else tail = mid - 1;
    }
    return (g[m] - g[head]) - 1LL * (m - head) * lim;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + A[i];
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
    sort(B + 1, B + m + 1);
    for (int i = 1; i <= m; i++) g[i] = g[i - 1] + B[i];

    ans = 1e18;
    for (int i = 1; i <= n; i++) ans = min(ans, gao1(A[i]) + gao2(A[i]));
    for (int i = 1; i <= m; i++) ans = min(ans, gao1(B[i]) + gao2(B[i]));
    printf("%lld\n", ans);
    return 0;
}

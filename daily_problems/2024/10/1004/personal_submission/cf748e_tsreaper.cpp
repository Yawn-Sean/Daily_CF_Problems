#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define MAXA ((int) 1e7)
using namespace std;

int n, K, m, A[MAXN + 10];

long long f[MAXA + 10];

long long calc(int x) {
    memset(f, 0, sizeof(long long) * (m + 3));
    f[x] = 1;
    for (int i = x + 1; i <= m; i++) f[i] = max(f[i - 1], f[i / 2] + f[i - i / 2]);

    long long ret = 0;
    for (int i = 1; i <= n; i++) ret += f[A[i]];
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    long long sm = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        m = max(m, A[i]);
        sm += A[i];
    }
    if (sm < K) { printf("-1\n"); return 0; }

    int head = 1, tail = m;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (calc(mid) >= K) head = mid;
        else tail = mid - 1;
    }
    printf("%d\n", head);
    return 0;
}

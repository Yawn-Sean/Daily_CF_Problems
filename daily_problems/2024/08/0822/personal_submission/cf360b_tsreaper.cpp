#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, K, A[MAXN + 10];

int f[MAXN + 10];

int dp(long long lim) {
    int ret = n;
    for (int i = 1; i <= n; i++) {
        f[i] = i - 1;
        for (int j = 1; j < i; j++) if (abs(A[i] - A[j]) <= lim * (i - j))
            f[i] = min(f[i], f[j] + i - j - 1);
        ret = min(ret, f[i] + n - i);
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    long long head = 0, tail = 2e9;
    while (head < tail) {
        long long mid = (head + tail) >> 1;
        if (dp(mid) <= K) tail = mid;
        else head = mid + 1;
    }
    printf("%lld\n", head);
    return 0;
}

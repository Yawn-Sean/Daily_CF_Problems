#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXM ((int) 1e5)
using namespace std;
typedef pair<long long, long long> pll;

int n, m, K, A[MAXN + 10], B[MAXN + 10];

pll calc(int len) {
    long long self = 0, pool = 0;
    for (int i = 1; i <= len; i++) {
        int idx = n - len + i;
        if (B[i] <= A[idx]) self += B[i];
        else self += A[idx], pool += B[i] - A[idx];
    }
    return pll(self, pool);
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= m; i++) scanf("%d", &B[i]);
    sort(B + 1, B + m + 1);

    int head = 0, tail = min(n, m);
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        if (calc(mid).second <= K) head = mid;
        else tail = mid - 1;
    }

    pll p = calc(head);
    p.first -= min(K - p.second, p.first);
    printf("%d %lld\n", head, p.first);
    return 0;
}

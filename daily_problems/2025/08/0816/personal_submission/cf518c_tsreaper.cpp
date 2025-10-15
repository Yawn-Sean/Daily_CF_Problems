#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, K, A[MAXN + 5], B[MAXN + 5];
long long ans;

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        B[A[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        int x; scanf("%d", &x);
        int idx = B[x];
        ans += (idx - 1) / K + 1;
        if (idx == 1) continue;
        int y = A[idx - 1];
        swap(A[idx - 1], A[idx]);
        swap(B[x], B[y]);
    }
    printf("%lld\n", ans);
    return 0;
}

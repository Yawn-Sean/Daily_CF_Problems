#include <bits/stdc++.h>
#define MAXN 30
using namespace std;

int n, m, V, A[MAXN + 5], B[MAXN + 5], C[MAXN + 5], P[MAXN + 5];
long long ans;

int AA[MAXN + 5];

void dfs(int dep, bool flag) {
    int rem = m - dep;
    if (rem % 2 == 0) {
        long long sm = 0;
        for (int i = 1; i <= n; i++) sm += 1LL * A[i] * C[i];
        ans = max(ans, sm);
    }
    if (rem == 0) return;

    for (int i = 1; i <= n; i++) AA[i] = A[P[i]];
    for (int i = 1; i <= n; i++) A[i] = AA[i] + V;
    dfs(dep + 1, true);
    for (int i = 1; i <= n; i++) AA[P[i]] = A[i];
    for (int i = 1; i <= n; i++) A[i] = AA[i] - V;

    if (flag) {
        for (int i = 1; i <= n; i++) A[i] ^= B[i];
        dfs(dep + 1, false);
        for (int i = 1; i <= n; i++) A[i] ^= B[i];
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &V);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &C[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &P[i]);

    ans = -1e18;
    dfs(0, true);
    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXM ((int) 2e5)
#define MAXQ ((int) 2e5)
#define MOD 998244353
using namespace std;

int n, m, K, q, X[MAXQ + 10], Y[MAXQ + 10];

bool R[MAXN + 10], C[MAXM + 10];
int cntR, cntC;

void solve() {
    scanf("%d%d%d%d", &n, &m, &K, &q);
    for (int i = 1; i <= q; i++) scanf("%d%d", &X[i], &Y[i]);

    for (int i = 1; i <= n; i++) R[i] = false;
    for (int j = 1; j <= m; j++) C[j] = false;
    cntR = cntC = 0;
    int p = q;
    for (int i = q; i > 0; i--) {
        if ((R[X[i]] || cntC == m) && (C[Y[i]] || cntR == n)) p--;
        if (!R[X[i]]) R[X[i]] = true, cntR++;
        if (!C[Y[i]]) C[Y[i]] = true, cntC++;
    }

    long long ans = 1;
    for (int i = 1; i <= p; i++) ans = ans * K % MOD;
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

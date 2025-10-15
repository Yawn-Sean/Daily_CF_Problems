#include <bits/stdc++.h>
#define MAXN ((int) 1e7)
#define INF ((long long) 9e18)
using namespace std;

int n;
long long l, r, X, Y, Z, ans, A[MAXN + 5], B[MAXN + 5];

void solve() {
    scanf("%d%lld%lld%lld%lld%lld%lld%lld", &n, &l, &r, &X, &Y, &Z, &B[1], &B[2]);
    for (int i = 3; i <= n; i++) B[i] = (B[i - 2] * X + B[i - 1] * Y + Z) & ((1LL << 32) - 1);
    for (int i = 1; i <= n; i++) A[i] = B[i] % (r - l + 1) + l;

    ans = INF;
    long long mn = A[1];
    for (int i = 1; i <= n; i++) {
        if (mn < A[i]) ans = min(ans, A[i] * mn);
        mn = min(mn, A[i]);
    }
    long long mx = A[n];
    for (int i = n; i > 0; i--) {
        if (mx > A[i]) ans = min(ans, A[i] * mx);
        mx = max(mx, A[i]);
    }
    if (ans < INF) printf("%lld\n", ans);
    else printf("IMPOSSIBLE\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

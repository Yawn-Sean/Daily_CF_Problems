#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, K, ans, A[MAXN + 5], B[MAXN + 5], C[MAXN + 5];

int f[MAXN * 2 + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &B[i], &C[i]);

    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[A[i]] = 1;
    for (int i = 1; i <= m; i++) mp[B[i]] = 1;
    K = 0;
    for (auto &p : mp) p.second = ++K;
    for (int i = 1; i <= n; i++) A[i] = mp[A[i]];
    for (int i = 1; i <= m; i++) B[i] = mp[B[i]];

    for (int i = 1; i <= K; i++) f[i] = 0;
    for (int i = 1; i <= m; i++) f[B[i]] = max(f[B[i]], C[i]);
    for (int i = K - 1; i > 0; i--) f[i] = max(f[i], f[i + 1]);

    ans = 1;
    for (int i = 1, j = 1, mx = 0, cnt = 0; i <= n; ) {
        mx = max(mx, A[i]);
        cnt++;
        if (f[mx] < cnt) {
            if (i == j) { printf("-1\n"); return; }
            ans++;
            mx = 0;
            cnt = 0;
            j = i;
        } else {
            i++;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

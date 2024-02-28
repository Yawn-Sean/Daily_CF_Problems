#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, L, R, S;

int ans[MAXN + 10];
bool vis[MAXN + 10];

int calc(int L, int R) {
    if (L > R) return 0;
    int len = (R - L + 1);
    return (L + R) * len / 2;
}

void solve() {
    scanf("%d%d%d%d", &n, &L, &R, &S);
    int len = R - L + 1;
    if (S < calc(1, len) || S > calc(n - len + 1, n)) { printf("-1\n"); return; }

    memset(ans, 0, sizeof(int) * (n + 3));
    memset(vis, 0, sizeof(bool) * (n + 3));
    for (int i = 1, j = L; i <= n; i++) {
        int rem = R - j;
        if (i + calc(i + 1, i + rem) <= S && S <= i + calc(n - rem + 1, n))
            ans[j++] = i, S -= i;
    }
    for (int i = L; i <= R; i++) vis[ans[i]] = true;
    for (int i = 1, j = 1; i <= n; i++) if (ans[i] == 0) {
        while (vis[j]) j++;
        ans[i] = j++;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

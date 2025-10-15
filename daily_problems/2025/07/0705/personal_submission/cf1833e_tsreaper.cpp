#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, A[MAXN + 5];
int vis[MAXN + 5], f[MAXN + 5];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int ans1 = 0, ans2 = 0, w = 0;
    for (int i = 1; i <= n; i++) vis[i] = f[i] = 0;
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        int j, cnt = 0;
        for (j = i; !vis[j]; j = A[j]) {
            vis[j] = i;
            f[j] = ++cnt;
        }
        if (vis[j] != i) continue;
        int det = cnt + 1 - f[j];
        if (det > 2) ans1++, ans2++;
        else w++;
    }
    if (w > 0) ans1++, ans2 += w;
    printf("%d %d\n", ans1, ans2);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

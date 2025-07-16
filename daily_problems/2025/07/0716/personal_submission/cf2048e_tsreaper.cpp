#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, ans[MAXN * 2 + 5][MAXN * 2 + 5];

void solve() {
    scanf("%d%d", &n, &m);
    if (m >= n * 2) { printf("NO\n"); return; }
    for (int i = 1; i <= n * 2; i++) for (int j = 1, now = i; j <= n; j++) for (int k = 0; k < 2; k++) {
        ans[i][now] = j;
        now++;
        if (now > n * 2) now = 1;
    }
    printf("YES\n");
    for (int i = 1; i <= n * 2; i++) for (int j = 1; j <= m; j++) printf("%d%c", ans[i][j], "\n "[j < m]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

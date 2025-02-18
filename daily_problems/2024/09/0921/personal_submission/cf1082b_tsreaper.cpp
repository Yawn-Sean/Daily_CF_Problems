#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, ans;
char s[MAXN + 10];

int f[MAXN + 10], g[MAXN + 10];

int main() {
    scanf("%d%s", &n, s + 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (s[i] == 'G') cnt++;
    if (cnt == n) { printf("%d\n", n); return 0; }

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'G') f[i] = f[i - 1] + 1;
        else f[i] = 0;
    }
    for (int i = n; i > 0; i--) {
        if (s[i] == 'G') g[i] = g[i + 1] + 1;
        else g[i] = 0;
    }

    ans = 0;
    for (int i = 1; i <= n; i++) if (s[i] == 'S') {
        int t = f[i - 1] + g[i + 1];
        if (t == cnt) ans = max(ans, cnt);
        else ans = max(ans, t + 1);
    }
    printf("%d\n", ans);
    return 0;
}

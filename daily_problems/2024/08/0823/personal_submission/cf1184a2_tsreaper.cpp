#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, ans;
char s[MAXN + 10];

int f[MAXN + 10];
bool vis[MAXN + 10];

int main() {
    scanf("%d%s", &n, s);
    for (int k = 1; k <= n; k++) {
        int g = gcd(k, n);
        if (g < k) { ans += f[g]; continue; }
        memset(vis, 0, sizeof(bool) * (n + 3));
        f[k] = 1;
        for (int i = 0; i < n; i++) if (!vis[i]) {
            int cnt = 0;
            for (int j = i; !vis[j]; j = (j - k + n) % n) vis[j] = true, cnt += s[j] - '0';
            if (cnt & 1) { f[k] = 0; break; }
        }
        ans += f[k];
    }
    printf("%d\n", ans);
    return 0;
}

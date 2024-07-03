#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, m, ans;
bool vis[MAXN + 10][2];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) if (!vis[i][0] && !vis[i][1]) {
        int now = i, d = 1;
        while (!vis[now][d]) {
            vis[now][d] = true;
            now += (m - 1) * 2 * (d ? 1 : -1);
            if (now <= 0) {
                int t = -now;
                if ((t / (n - 1)) % 2) now = n - 1 - t % (n - 1);
                else now = t % (n - 1) + 2, d = 1 - d;
            } else {
                int t = now - 1;
                if ((t / (n - 1)) % 2) now = n - t % (n - 1), d = 1 - d;
                else now = t % (n - 1) + 1;
            }
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

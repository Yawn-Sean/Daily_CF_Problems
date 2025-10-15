#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
#define INF ((int) 1e9)
using namespace std;

bool vis[MAXN + 5];

void solve() {
    int b, n; scanf("%d%d", &b, &n);
    memset(vis, 0, sizeof(bool) * (n + 3));

    long long now = b % n;
    for (int i = 1; !vis[now]; i++, now = now * b % n) {
        vis[now] = true;
        if (now == 0) { printf("1 %d\n", i); return; }
        if (now == 1) { printf("2 %d\n", i); return; }
        if (now == n - 1) { printf("3 %d\n", i); return; }
    }
    printf("0\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

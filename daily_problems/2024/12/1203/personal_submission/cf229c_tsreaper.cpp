#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, m, deg[MAXN + 5];
long long ans;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        deg[x]++; deg[y]++;
    }
    for (int i = 1; i <= n; i++) {
        int x = deg[i], y = n - 1 - deg[i];
        ans += 1LL * x * (x - 1) + 1LL * y * (y - 1) - 1LL * x * y;
    }
    printf("%lld\n", ans / 6);
    return 0;
}

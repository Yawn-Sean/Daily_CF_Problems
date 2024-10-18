#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;
long long ans;

vector<int> e[MAXN + 10];
int deg[MAXN + 10], f[MAXN + 10];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        deg[x]++; deg[y]++;
    }

    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int fn : e[i]) f[i] = max(f[i], f[fn] + 1);
        ans = max(ans, 1LL * f[i] * deg[i]);
    }
    printf("%lld\n", ans);
    return 0;
}

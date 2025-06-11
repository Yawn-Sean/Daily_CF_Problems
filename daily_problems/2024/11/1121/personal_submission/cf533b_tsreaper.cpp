#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;

int n, A[MAXN + 5];

vector<int> e[MAXN + 5];
long long f[MAXN + 5][2];

void dfs(int sn) {
    long long g[2] = {0, -INF};
    for (int fn : e[sn]) {
        dfs(fn);
        long long x = max(g[0] + f[fn][0], g[1] + f[fn][1]);
        long long y = max(g[1] + f[fn][0], g[0] + f[fn][1]);
        g[0] = x; g[1] = y;
    }
    f[sn][0] = g[0];
    f[sn][1] = max(g[1], g[0] + A[sn]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d%d", &x, &A[i]);
        if (x > 0) e[x].push_back(i);
    }
    dfs(1);
    printf("%lld\n", max(f[1][0], f[1][1]));
    return 0;
}

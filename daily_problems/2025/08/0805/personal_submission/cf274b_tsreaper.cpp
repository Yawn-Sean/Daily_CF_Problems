#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, A[MAXN + 5];

vector<int> e[MAXN + 5];
long long f[MAXN + 5], g[MAXN + 5];

void dfs(int sn, int fa) {
    for (int fn : e[sn]) if (fn != fa) {
        dfs(fn, sn);
        long long det = A[sn] - A[fn];
        if (det >= 0) {
            f[sn] = max(f[sn], f[fn] + det);
            g[sn] = max(g[sn], g[fn]);
        } else {
            f[sn] = max(f[sn], f[fn]);
            g[sn] = max(g[sn], g[fn] - det);
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    dfs(1, 0);
    long long ans = f[1] + g[1] + abs(A[1] - f[1] + g[1]);
    printf("%lld\n", ans);
    return 0;
}

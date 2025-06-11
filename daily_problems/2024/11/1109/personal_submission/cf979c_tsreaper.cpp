#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, X, Y;

vector<int> e[MAXN + 10];
int sz[MAXN + 10];

int dfs(int sn, int fa) {
    sz[sn] = 1;
    for (int fn : e[sn]) if (fn != fa) sz[sn] += dfs(fn, sn);
    return sz[sn];
}

int main() {
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    dfs(X, 0);
    long long ans = sz[Y];
    dfs(Y, 0);
    ans *= sz[X];
    printf("%lld\n", 1LL * n * (n - 1) - ans);
    return 0;
}

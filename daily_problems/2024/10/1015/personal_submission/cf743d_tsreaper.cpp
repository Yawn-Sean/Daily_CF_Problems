#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<long long, long long> pll;

int n, A[MAXN + 10];
long long ans;

vector<int> e[MAXN + 10];

pll dfs(int sn, int fa) {
    long long sm = A[sn], mx = -INF;
    for (int fn : e[sn]) if (fn != fa) {
        pll p = dfs(fn, sn);
        if (mx > -INF) ans = max(ans, mx + p.second);
        sm += p.first;
        mx = max(mx, p.second);
    }
    mx = max(mx, sm);
    return {sm, mx};
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    ans = -INF;
    dfs(1, 0);
    if (ans > -INF) printf("%lld\n", ans);
    else printf("Impossible\n");
    return 0;
}

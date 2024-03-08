#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define INF ((long long) 1e18)
using namespace std;

int n, A[MAXN + 10];
long long ans;

vector<int> e[MAXN + 10], v[MAXN + 10];

long long dfs(int sn, int fa) {
    long long ret = A[sn];
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (fn == fa) continue;
        long long tmp = dfs(fn, sn) - v[sn][i];
        tmp = max(tmp, 0LL);
        ans = max(ans, ret + tmp);
        ret = max(ret, tmp + A[sn]);
    }
    ans = max(ans, ret);
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}

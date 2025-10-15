#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, K;
long long ans;
bool flag[MAXN + 5];

vector<int> e[MAXN + 5];

int dfs(int sn, int fa) {
    int sz = flag[sn] ? 1 : 0;
    for (int fn : e[sn]) if (fn != fa) {
        int t = dfs(fn, sn);
        ans += min(t, K * 2 - t);
        sz += t;
    }
    return sz;
}

int main() {
    scanf("%d%d", &n, &K);
    for (int i = 1; i <= K * 2; i++) {
        int x; scanf("%d", &x);
        flag[x] = true;
    }
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}

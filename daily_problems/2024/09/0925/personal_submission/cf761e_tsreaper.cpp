#include <bits/stdc++.h>
#define MAXN 30
using namespace std;

int n;
long long ans[MAXN + 5][2];

vector<int> e[MAXN + 5];
int deg[MAXN + 5];

void dfs(int sn, int fa, long long x, long long y, long long len, int from) {
    ans[sn][0] = x; ans[sn][1] = y;
    short dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    int k = 0;
    for (int fn : e[sn]) if (fn != fa) {
        while (fa > 0 && k == (from + 2) % 4) k++;
        dfs(fn, sn, x + len * dir[k][0], y + len * dir[k][1], len >> 1, k);
        k++;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        deg[x]++; deg[y]++;
    }

    for (int i = 1; i <= n; i++) if (deg[i] > 4) { printf("NO\n"); return 0; }
    dfs(1, 0, 0, 0, 1LL << 50, 0);
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%lld %lld\n", ans[i][0], ans[i][1]);
    return 0;
}

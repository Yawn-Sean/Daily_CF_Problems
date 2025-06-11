#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m;
long long ans;

vector<int> e[MAXN + 10];
int f[MAXN + 10][2];
long long g[MAXN + 10][2];

void dfs1(int sn, int fa) {
    for (int fn : e[sn]) if (fn != fa) {
        dfs1(fn, sn);
        f[sn][0] += f[fn][1];
        f[sn][1] += f[fn][0];
        g[sn][0] += g[fn][1];
        g[sn][1] += f[fn][0] + g[fn][0];
    }
    f[sn][0]++;
}

void dfs2(int sn, int fa, int f0, long long g0, int f1, long long g1) {
    ans += g[sn][0] + g0 + g[sn][1] + g1;
    for (int fn : e[sn]) if (fn != fa) {
        int nf0 = f1 + f[sn][1] - f[fn][0];
        long long ng0 = g1 + g[sn][1] - f[fn][0] - g[fn][0];
        int nf1 = f0 + f[sn][0] - f[fn][1];
        long long ng1 = g0 + nf1 + g[sn][0] - g[fn][1];
        dfs2(fn, sn, nf0, ng0, nf1, ng1);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    dfs1(1, 0);
    dfs2(1, 0, 0, 0, 0, 0);
    printf("%lld\n", ans / 2);
    return 0;
}

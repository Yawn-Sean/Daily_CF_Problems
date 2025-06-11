#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<pii> qry[MAXN + 5];
long long ans1[MAXN + 5], ans2[MAXN + 5];

vector<int> e[MAXN + 5];
bool vis[MAXN + 5];
int pa[MAXN + 5], sz[MAXN + 5], dep[MAXN + 5];
long long f[MAXN + 5];

int root[MAXN + 5];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void dfs1(int sn, int fa, int d) {
    pa[sn] = fa; sz[sn] = 1; dep[sn] = d;
    for (int fn : e[sn]) if (fn != fa) {
        dfs1(fn, sn, d + 1);
        f[sn] += f[fn] + sz[fn];
        sz[sn] += sz[fn];
    }
}

void dfs2(int sn, long long fv) {
    for (int fn : e[sn]) if (fn != pa[sn]) {
        long long tmp = fv + f[sn] - (f[fn] + sz[fn]);
        tmp += n - sz[fn];
        dfs2(fn, tmp);
    }

    for (pii p : qry[sn]) {
        int fn = p.first, idx = p.second;
        if (!vis[fn]) continue;
        int r = findroot(fn), a = pa[r], len = dep[sn] + dep[fn] - 2 * dep[a] + 1;
        if (a == sn) {
            long long tmp = fv + f[sn] - (f[r] + sz[r]);
            ans2[idx] = 1LL * (n - sz[r]) * sz[fn];
            ans1[idx] += (n - sz[r]) * f[fn] + sz[fn] * tmp;
        } else {
            ans2[idx] = 1LL * sz[sn] * sz[fn];
            ans1[idx] += sz[sn] * f[fn] + sz[fn] * f[sn];
        }
        ans1[idx] += len * ans2[idx];
    }

    for (int fn : e[sn]) if (fn != pa[sn]) root[findroot(fn)] = findroot(sn);
    vis[sn] = true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        qry[x].push_back({y, i});
        qry[y].push_back({x, i});
    }

    for (int i = 1; i <= n; i++) root[i] = i;
    dfs1(1, 0, 1); dfs2(1, 0);
    for (int i = 1; i <= m; i++) printf("%.12f\n", 1.0 * ans1[i] / ans2[i]);
    return 0;
}

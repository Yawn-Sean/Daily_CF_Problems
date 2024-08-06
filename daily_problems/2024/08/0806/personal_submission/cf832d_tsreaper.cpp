#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 20
using namespace std;

int n, q;

vector<int> e[MAXN + 10];
int dep[MAXN + 10], pa[MAXN + 10][MAXP];

void dfs(int sn, int d) {
    dep[sn] = d;
    for (int p = 1; p < MAXP; p++) pa[sn][p] = pa[pa[sn][p - 1]][p - 1];
    for (int fn : e[sn]) dfs(fn, d + 1);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

int gao(int x, int y, int z) {
    int a = lca(x, z), u = lca(x, y), v = lca(y, z);
    return max(0, dep[u] - dep[a]) - max(0, dep[v] - dep[a]) + (dep[z] - dep[a]);
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &pa[i][0]);
        e[pa[i][0]].push_back(i);
    }
    dfs(1, 1);

    while (q--) {
        vector<int> vec;
        for (int i = 0; i < 3; i++) {
            int x; scanf("%d", &x);
            vec.push_back(x);
        }
        int ans = 0;
        for (int i = 0; i < 6; i++) {
            ans = max(ans, gao(vec[0], vec[1], vec[2]));
            next_permutation(vec.begin(), vec.end());
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}

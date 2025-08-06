#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXP 20
using namespace std;

int n, X[MAXN + 5];
long long Y[MAXN + 5];

vector<int> e[MAXN + 5];
int pa[MAXN + 5][MAXP], dep[MAXN + 5];

bool check(int i, int j) {
    int k = pa[j][0];
    long long xa = X[j] - X[i], ya = Y[j] - Y[i];
    long long xb = X[k] - X[j], yb = Y[k] - Y[j];
    return xa * yb - xb * ya > 0;
}

void dfs(int sn, int d) {
    dep[sn] = d;
    for (int fn : e[sn]) dfs(fn, d + 1);
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    for (int p = MAXP - 1; p >= 0; p--) if (dep[pa[x][p]] >= dep[y]) x = pa[x][p];
    if (x == y) return x;
    for (int p = MAXP - 1; p >= 0; p--) if (pa[x][p] != pa[y][p]) x = pa[x][p], y = pa[y][p];
    return pa[x][0];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%lld", &X[i], &Y[i]);

    for (int i = n - 1; i <= n; i++) for (int p = 0; p < MAXP; p++) pa[i][p] = n;
    for (int i = n - 2; i > 0; i--) {
        if (!check(i, i + 1)) pa[i][0] = i + 1;
        else {
            int now = i + 1;
            for (int p = MAXP - 1; p >= 0; p--) {
                int nxt = pa[now][p];
                if (nxt < n && check(i, nxt)) now = nxt;
            }
            pa[i][0] = pa[now][0];
        }
        for (int p = 1; p < MAXP; p++) pa[i][p] = pa[pa[i][p - 1]][p - 1];
    }

    for (int i = 1; i < n; i++) e[pa[i][0]].push_back(i);
    dfs(n, 1);

    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d%c", lca(x, y), "\n "[i < q]);
    }
    return 0;
}

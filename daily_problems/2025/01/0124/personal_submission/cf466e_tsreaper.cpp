#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MAXQ ((int) 1e5)
using namespace std;

int n, q, QRY[MAXQ + 5][3];

vector<int> e[MAXN + 5];
int deg[MAXN + 5], dep[MAXN + 5];
int clk, bgn[MAXN + 5], fin[MAXN + 5];

int root[MAXN + 5], who[MAXQ + 5], lim[MAXQ + 5];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void dfs(int sn, int d) {
    dep[sn] = d;
    bgn[sn] = ++clk;
    for (int fn : e[sn]) dfs(fn, d + 1);
    fin[sn] = clk;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1, j = 0; i <= q; i++) {
        scanf("%d", &QRY[i][0]);
        if (QRY[i][0] == 1) {
            scanf("%d%d", &QRY[i][1], &QRY[i][2]);
            e[QRY[i][2]].push_back(QRY[i][1]);
            deg[QRY[i][1]]++;
        } else if (QRY[i][0] == 2) {
            scanf("%d", &QRY[i][1]);
            QRY[i][2] = ++j;
        } else {
            scanf("%d%d", &QRY[i][1], &QRY[i][2]);
        }
    }

    for (int i = 1; i <= n; i++) if (deg[i] == 0) dfs(i, 1);
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= q; i++) {
        int op = QRY[i][0], x = QRY[i][1], y = QRY[i][2];
        if (op == 1) root[x] = y;
        else if (op == 2) who[y] = x, lim[y] = dep[findroot(x)];
        else {
            int z = who[y];
            if (bgn[z] >= bgn[x] && bgn[z] <= fin[x] && dep[x] >= lim[y]) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

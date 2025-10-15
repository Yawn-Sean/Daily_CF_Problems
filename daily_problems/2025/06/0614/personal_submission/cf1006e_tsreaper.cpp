#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q;

vector<int> e[MAXN + 5];
int clk, dfn[MAXN + 5], bgn[MAXN + 5], fin[MAXN + 5];

void dfs(int sn) {
    dfn[++clk] = sn;
    bgn[sn] = clk;
    for (int fn : e[sn]) dfs(fn);
    fin[sn] = clk;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        e[x].push_back(i);
    }
    dfs(1);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        if (fin[x] - bgn[x] + 1 < y) printf("-1\n");
        else printf("%d\n", dfn[bgn[x] + y - 1]);
    }
    return 0;
}

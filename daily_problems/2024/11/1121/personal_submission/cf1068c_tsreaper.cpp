#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m;
vector<int> ans[MAXN + 5];

bool G[MAXN + 5][MAXN + 5];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        G[x][y] = G[y][x] = true;
    }

    for (int i = 1; i <= n; i++) ans[i].push_back(i);
    int now = n;
    for (int i = 2; i <= n; i++) for (int j = 1; j < i; j++) if (G[i][j]) {
        now++;
        ans[i].push_back(now);
        ans[j].push_back(now);
    }

    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i].size());
        for (int y : ans[i]) printf("%d %d\n", i, y);
    }
    return 0;
}

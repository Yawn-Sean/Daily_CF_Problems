#include <bits/stdc++.h>
#define MAXN 7
using namespace std;

int n, m, ans, A[MAXN + 5], B[MAXN * MAXN + 5][2];
bool vis[7][7];

void dfs(int dep) {
    if (dep > n) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            int x = A[B[i][0]], y = A[B[i][1]];
            if (x > y) swap(x, y);
            if (!vis[x][y]) vis[x][y] = true, cnt++;
        }
        ans = max(ans, cnt);
        for (int i = 1; i <= m; i++) {
            int x = A[B[i][0]], y = A[B[i][1]];
            if (x > y) swap(x, y);
            vis[x][y] = false;
        }
        return;
    }

    for (int i = 1; i <= 6; i++) {
        A[dep] = i;
        dfs(dep + 1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &B[i][0], &B[i][1]);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}

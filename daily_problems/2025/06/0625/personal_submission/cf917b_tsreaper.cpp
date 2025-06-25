#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m;
char g[MAXN + 5][MAXN + 5];

int f[MAXN + 5][MAXN + 5][26];

int dp(int u, int v, int c) {
    int &ret = f[u][v][c];
    if (ret) return ret;
    
    for (int uu = 1; uu <= n; uu++) if (g[u][uu] > 0 && g[u][uu] - 'a' >= c)
        if (dp(v, uu, g[u][uu] - 'a') == -1) return ret = 1;
    return ret = -1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        char c[3]; scanf("%d%d%s", &x, &y, c);
        g[x][y] = c[0];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp(i, j, 0) == 1) printf("A");
            else printf("B");
        }
        printf("\n");
    }
    return 0;
}

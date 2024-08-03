#include <bits/stdc++.h>
#define MAXN 500
using namespace std;

int n, m;
bool g[MAXN + 10][MAXN + 10];

vector<int> e[MAXN + 10];
int col[MAXN + 10];

bool check(int x, int y) {
    return abs(x - y) <= 1;
}

void bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (!col[fn]) q.push(fn), col[fn] = 4 - col[sn];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        g[x][y] = g[y][x] = true;
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        if (i != j && !g[i][j]) e[i].push_back(j);
    
    for (int i = 1; i <= n; i++) if (!col[i]) {
        if (e[i].empty()) col[i] = 2;
        else bfs(i);
    }

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) {
        if (g[i][j] != check(col[i], col[j])) { printf("No\n"); return 0; }
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++) printf("%c", col[i] - 1 + 'a');
    printf("\n");
    return 0;
}

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

int n, m, ans[MAXN + 5];
bool g[MAXN + 5][MAXN + 5];

vector<int> e[MAXN + 5];
int col[MAXN + 5];

vector<int> vec[MAXN + 5][2];
int from[MAXN + 5][MAXN + 5];

bool bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        vec[S][col[sn]].push_back(sn);
        for (int fn : e[sn]) {
            if (col[fn] >= 0) {
                if (col[fn] == col[sn]) return false;
            } else {
                q.push(fn); col[fn] = col[sn] ^ 1;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    if (n % 2 == 1 || n > MAXN) { printf("impossible\n"); return 0; }
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        g[x][y] = g[y][x] = true;
    }

    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (!g[i][j])
        e[i].push_back(j), e[j].push_back(i);
    for (int i = 1; i <= n; i++) col[i] = -1;
    for (int i = 1; i <= n; i++) if (col[i] < 0) if (!bfs(i)) { printf("impossible\n"); return 0; }

    for (int i = 0; i <= n; i++) for (int j = 0; j <= n / 2; j++) from[i][j] = -1;
    from[0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= n / 2; j++)
        for (int x : vector<int>{vec[i][0].size(), vec[i][1].size()})
            if (j - x >= 0 && from[i - 1][j - x] >= 0) from[i][j] = j - x;
    
    if (from[n][n / 2] >= 0) {
        for (int i = n, j = n / 2; i > 0; j = from[i][j], i--) {
            int det = j - from[i][j];
            if (vec[i][0].size() == det) for (int x : vec[i][0]) ans[x] = 1;
            else for (int x : vec[i][1]) ans[x] = 1;
        }
        for (int i = 1; i <= n; i++)
            if (ans[i]) printf("r\n");
            else printf("b\n");
    } else {
        printf("impossible\n");
    }
    return 0;
}

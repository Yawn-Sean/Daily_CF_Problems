#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m;

vector<int> e[MAXN + 10];
int col[MAXN + 10];

bool bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) {
            if (!col[fn]) {
                q.push(fn); col[fn] = 3 - col[sn];
            } else if (col[sn] == col[fn]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) if (!col[i])
        if (!bfs(i)) { printf("-1\n"); return 0; }

    vector<int> ans[2];
    for (int i = 1; i <= n; i++) ans[col[i] - 1].push_back(i);
    for (int i = 0; i < 2; i++) {
        printf("%d\n", ans[i].size());
        for (int x : ans[i]) printf("%d ", x);
        printf("\n");
    }
    return 0;
}

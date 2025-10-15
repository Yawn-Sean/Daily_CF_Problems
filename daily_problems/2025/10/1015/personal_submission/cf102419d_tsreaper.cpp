#include  <bits/stdc++.h>
#define MAXN ((int) 3e5)
#define MAXA (1 << 20)
using namespace std;

int n, m, A[MAXN + 5];
vector<int> ans;

vector<int> e[MAXN + 5];
int col[MAXN + 5];
bool ban[MAXA];

bool bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        if (col[sn]) ans.push_back(sn);
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
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (A[x] == A[y]) e[x].push_back(y), e[y].push_back(x);
        else ban[A[x] ^ A[y]] = true;
    }

    for (int i = 1; i <= n; i++) col[i] = -1;
    for (int i = 1; i <= n; i++) if (col[i] == -1)
        if (!bfs(i)) { printf("-1\n"); return 0; }

    printf("%d ", ans.size());
    for (int i = 1; ; i++) if (!ban[i]) { printf("%d\n", i); break; }
    for (int x : ans) printf("%d ", x);
    printf("\n");
    return 0;
}

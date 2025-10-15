#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

int n, m;

vector<int> e[MAXN + 5], v[MAXN + 5];
int col[MAXN + 5];

bool bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i], val = v[sn][i];
            if (col[fn] >= 0) {
                if ((col[sn] ^ col[fn]) != val) return false;
            } else {
                q.push(fn); col[fn] = col[sn] ^ val;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z ^ 1);
        e[y].push_back(x); v[y].push_back(z ^ 1);
    }

    memset(col, -1, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) if (col[i] < 0)
        if (!bfs(i)) { printf("Impossible\n"); return 0; }
    vector<int> vec;
    for (int i = 1; i <= n; i++) if (col[i]) vec.push_back(i);
    printf("%d\n", vec.size());
    for (int i = 0; i < vec.size(); i++) printf("%d%c", vec[i], "\n "[i + 1 < vec.size()]);
    return 0;
}

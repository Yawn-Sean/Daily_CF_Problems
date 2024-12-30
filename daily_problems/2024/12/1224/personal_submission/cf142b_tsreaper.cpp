#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, ans;

vector<int> e[MAXN * MAXN];
int col[MAXN * MAXN];
short dir[8][2] = {1, 2, 2, 1, -1, -2, -2, -1, 1, -2, -2, 1, -1, 2, 2, -1};

int bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 1;
    int cnt[3] = {0};
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        cnt[col[sn]]++;
        for (int fn : e[sn]) if (!col[fn])
            q.push(fn), col[fn] = 3 - col[sn];
    }
    return max(cnt[1], cnt[2]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < 8; k++) {
        int ii = i + dir[k][0], jj = j + dir[k][1];
        if (ii >= 0 && jj >= 0 && ii < n && jj < m) {
            int sn = i * m + j, fn = ii * m + jj;
            e[sn].push_back(fn);
        }
    }
    for (int i = 0; i < n * m; i++) if (!col[i]) ans += bfs(i);
    printf("%d\n", ans);
    return 0;
}

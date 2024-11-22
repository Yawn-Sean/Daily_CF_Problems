#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m, A[MAXN + 10][MAXN + 10];
long long K;

int root[MAXN * MAXN + 10], sz[MAXN * MAXN + 10];
bool vis[MAXN + 10][MAXN + 10];
short dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void bfs(int SI, int SJ) {
    queue<pii> q;
    q.push({SI, SJ}); vis[SI][SJ] = true;
    int need = K / A[SI][SJ] - 1, val = A[SI][SJ];
    while (!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second;
        for (int k = 0; need > 0 && k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            if (ii <= 0 || jj <= 0 || ii > n || jj > m || vis[ii][jj] || A[ii][jj] < val) continue;
            q.push({ii, jj}); vis[ii][jj] = true;
            need--;
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) printf("%d%c", vis[i][j] ? val : 0, "\n "[j < m]);
}

int main() {
    scanf("%d%d%lld", &n, &m, &K);
    vector<pii> vec;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        scanf("%d", &A[i][j]);
        vec.push_back({i, j});
    }
    sort(vec.begin(), vec.end(), [&](pii &a, pii &b) {
        return A[a.first][a.second] > A[b.first][b.second];
    });

    for (pii p : vec) {
        int i = p.first, j = p.second;
        int idx = (i - 1) * m + j;
        root[idx] = idx; sz[idx] = 1;
        for (int k = 0; k < 4; k++) {
            int ii = i + dir[k][0], jj = j + dir[k][1];
            int iidx = (ii - 1) * m + jj;
            if (ii < 1 || jj < 1 || ii > n || jj > m || sz[iidx] == 0) continue;
            int u = findroot(idx), v = findroot(iidx);
            if (u == v) continue;
            root[v] = u;
            sz[u] += sz[v];
        }
        if (K % A[i][j] > 0) continue;
        if (sz[idx] >= K / A[i][j]) {
            printf("YES\n");
            bfs(i, j);
            return 0;
        }
    }

    printf("NO\n"); return 0;
}

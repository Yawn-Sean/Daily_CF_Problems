#include <bits/stdc++.h>
#define MAXN 3000
using namespace std;
typedef pair<int, int> pii;

int n, m;

vector<int> e[MAXN + 10];
int dis[MAXN + 10][MAXN + 10];
vector<pii> vec1[MAXN + 10], vec2[MAXN + 10];

void bfs(int S) {
    memset(dis[S], -1, sizeof(int) * (n + 3));
    queue<int> q;
    q.push(S); dis[S][S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) {
            if (dis[S][fn] >= 0) continue;
            q.push(fn); dis[S][fn] = dis[S][sn] + 1;
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        bfs(i);
        for (int j = 1; j <= n; j++) vec1[j].push_back({dis[i][j], i});
        for (int j = 1; j <= n; j++) vec2[i].push_back({dis[i][j], j});
    }
    for (int i = 1; i <= n; i++) {
        sort(vec1[i].begin(), vec1[i].end(), greater<pii>());
        sort(vec2[i].begin(), vec2[i].end(), greater<pii>());
    }

    int ans = 0;
    vector<int> best;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j && dis[i][j] >= 0) {
        for (int x = 0; x < 3; x++) {
            int sn = vec1[i][x].second;
            if (dis[sn][i] < 0 || sn == i || sn == j) continue;
            for (int y = 0; y < 3; y++) {
                int fn = vec2[j][y].second;
                if (dis[j][fn] < 0 || fn == i || fn == j || fn == sn) continue;
                int len = dis[sn][i] + dis[i][j] + dis[j][fn];
                if (len > ans) {
                    ans = len;
                    best = {sn, i, j, fn};
                }
            }
        }
    }

    for (int x : best) printf("%d ", x);
    printf("\n");
    return 0;
}

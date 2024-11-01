#include <bits/stdc++.h>
#define MAXN 50
#define MAXVERT ((MAXN + 1) * (MAXN + 1) * 2)
#define INF ((int) 1e9)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, K, cnt[3];

vector<int> e[MAXVERT + 10];
vector<long long> v[MAXVERT + 10];
long long C[MAXN + 5][MAXN + 5];

int dis[MAXVERT + 10];
long long f[MAXVERT + 10];

int idx(int i, int j, int b) {
    return (i * (n + 1) + j) * 2 + b;
}

void bfs() {
    int S = idx(cnt[1], cnt[2], 0), T = idx(0, 0, 1);
    int lim = idx(cnt[1], cnt[2], 1);
    for (int i = 0; i <= lim; i++) dis[i] = INF;

    queue<int> q;
    q.push(S); dis[S] = 0; f[S] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            if (dis[fn] < dis[sn] + 1) continue;
            f[fn] = (f[fn] + f[sn] * v[sn][i]) % MOD;
            if (dis[fn] == dis[sn] + 1) continue;
            q.push(fn); dis[fn] = dis[sn] + 1;
        }
    }

    if (dis[T] == INF) printf("-1\n0\n");
    else printf("%d\n%lld\n", dis[T], f[T]);
}

int main() {
    scanf("%d%d", &n, &K); K /= 50;
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        cnt[x / 50]++;
    }

    for (int i = 0; i <= cnt[1]; i++) for (int j = 0; j <= cnt[2]; j++) {
        int ii = cnt[1] - i, jj = cnt[2] - j;
        int sn = idx(i, j, 0);
        for (int di = 0; di <= i; di++) for (int dj = 0; dj <= j; dj++) if (di + dj > 0 && di + dj * 2 <= K) {
            int fn = idx(i - di, j - dj, 1);
            e[sn].push_back(fn);
            v[sn].push_back(C[i][di] * C[j][dj] % MOD);
        }
        sn = idx(i, j, 1);
        for (int di = 0; di <= ii; di++) for (int dj = 0; dj <= jj; dj++) if (di + dj > 0 && di + dj * 2 <= K) {
            int fn = idx(i + di, j + dj, 0);
            e[sn].push_back(fn);
            v[sn].push_back(C[ii][di] * C[jj][dj] % MOD);
        }
    }

    bfs();
    return 0;
}

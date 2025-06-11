#include <bits/stdc++.h>
#define MAXN 70
#define INF ((int) 1e9)
using namespace std;

int n, X, Y, Z, ans;
char MAP[MAXN + 5][MAXN + 5];

int dis[MAXN + 5][MAXN + 5][MAXN + 5];
array<int, 3> from[MAXN + 5][MAXN + 5][MAXN + 5];

void bfs() {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) dis[i][j][k] = INF;
    queue<array<int, 3>> q;
    q.push({X, Y, Z}); dis[X][Y][Z] = 0;

    while (!q.empty()) {
        auto arr = q.front(); q.pop();
        int x = arr[0], y = arr[1], z = arr[2];

        auto check1 = [&](int t) {
            if (MAP[x][t] != MAP[y][z]) return;
            if (dis[t][y][z] < INF) return;
            q.push({t, y, z});
            dis[t][y][z] = dis[x][y][z] + 1;
            from[t][y][z] = {x, y, z};
        };

        auto check2 = [&](int t) {
            if (MAP[y][t] != MAP[x][z]) return;
            if (dis[x][t][z] < INF) return;
            q.push({x, t, z});
            dis[x][t][z] = dis[x][y][z] + 1;
            from[x][t][z] = {x, y, z};
        };

        auto check3 = [&](int t) {
            if (MAP[z][t] != MAP[x][y]) return;
            if (dis[x][y][t] < INF) return;
            q.push({x, y, t}); dis[x][y][t] = dis[x][y][z] + 1;
            from[x][y][t] = {x, y, z};
        };

        for (int i = 1; i <= n; i++) if (i != x && i != y && i != z) {
            check1(i);
            check2(i);
            check3(i);
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &X, &Y, &Z);
    for (int i = 1; i <= n; i++) scanf("%s", MAP[i] + 1);
    
    bfs();

    ans = INF;
    vector<int> ord = {1, 2, 3}, best = ord;
    for (int i = 0; i < 6; i++) {
        if (dis[ord[0]][ord[1]][ord[2]] < ans) {
            ans = dis[ord[0]][ord[1]][ord[2]];
            best = ord;
        }
        next_permutation(ord.begin(), ord.end());
    }

    printf("%d\n", ans < INF ? ans : -1);
    if (ans < INF) {
        vector<array<int, 2>> vec;
        for (int x = best[0], y = best[1], z = best[2]; x != X || y != Y || z != Z; ) {
            int xx = from[x][y][z][0];
            int yy = from[x][y][z][1];
            int zz = from[x][y][z][2];
            if (x != xx) vec.push_back({xx, x});
            if (y != yy) vec.push_back({yy, y});
            if (z != zz) vec.push_back({zz, z});
            x = xx; y = yy; z = zz;
        }
        reverse(vec.begin(), vec.end());
        for (auto &arr : vec) printf("%d %d\n", arr[0], arr[1]);
    }

    return 0;
}

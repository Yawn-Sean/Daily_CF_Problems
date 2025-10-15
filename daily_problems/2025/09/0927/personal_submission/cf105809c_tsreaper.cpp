#include <bits/stdc++.h>
#define MAXX 10
#define MAXN (MAXX * MAXX * MAXX)
#define INF ((int) 1e9)
using namespace std;

int X, Y, Z, K;
bool ban[MAXX + 1][MAXX + 1][MAXX + 1];

struct Edge { int fn, cap, nxt; };
vector<Edge> e;
int S, T, p[MAXN + 5], cur[MAXN + 5], dep[MAXN + 5];

void adde(int sn, int fn, int cap) {
    int idx = e.size();
    e.push_back({fn, cap, p[sn]});
    p[sn] = idx;
    idx = e.size();
    e.push_back({sn, 0, p[fn]});
    p[fn] = idx;
}

bool bfs() {
    queue<int> q;
    memset(dep, 0, sizeof(int) * (T + 1));

    q.push(S); dep[S] = 1;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (dep[fn] == 0 && e[i].cap > 0)
                q.push(fn), dep[fn] = dep[sn] + 1;
        }
    }
    return dep[T];
}

int dfs(int sn, int flow) {
    if (sn == T || flow == 0) return flow;

    int ret = 0;
    for (int &i = cur[sn]; i >= 0; i = e[i].nxt) {
        int fn = e[i].fn;
        if (dep[fn] != dep[sn] + 1) continue;
        int d = dfs(fn, min(flow - ret, e[i].cap));
        if (d == 0) continue;
        ret += d;
        e[i].cap -= d;
        e[i ^ 1].cap += d;
        if (ret == flow) return ret;
    }
    return ret;
}

int dinic() {
    int mf = 0;
    while (bfs()) {
        memcpy(cur, p, sizeof(int) * (T + 1));
        mf += dfs(S, INF);
    }
    return mf;
}

int main() {
    scanf("%d%d%d%d", &X, &Y, &Z, &K);
    for (int i = 1; i <= K; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        ban[x][y][z] = true;
    }

    S = 0; T = X * Y * Z + 1;
    for (int i = S; i <= T; i++) p[i] = -1;

    vector<array<int, 3>> dir;
    for (int i = -1; i <= 1; i += 2) for (int j = -2; j <= 2; j += 4) {
        array<int, 3> arr = {i, j, 0};
        for (int k = 0; k < 6; k++) {
            dir.push_back(arr);
            next_permutation(arr.begin(), arr.end());
        }
    }
    for (int x = 1; x <= X; x++) for (int y = 1; y <= Y; y++) for (int z = 1; z <= Z; z++) if (!ban[x][y][z]) {
        int idx = (x - 1) * Y * Z + (y - 1) * Z + z;
        if ((x + y + z) & 1) { adde(idx, T, 1); continue; }
        adde(S, idx, 1);
        for (auto &arr : dir) {
            int xx = x + arr[0], yy = y + arr[1], zz = z + arr[2];
            if (xx > 0 && yy > 0 && zz > 0 && xx <= X && yy <= Y && zz <= Z && !ban[xx][yy][zz]) {
                int iidx = (xx - 1) * Y * Z + (yy - 1) * Z + zz;
                adde(idx, iidx, 1);
            }
        }
    }

    int mf = dinic();
    printf("%d\n", X * Y * Z - K - mf);
    return 0;
}

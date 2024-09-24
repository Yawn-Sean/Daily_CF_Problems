#include <bits/stdc++.h>
#define MAXK 1000
#define MAXN 10
#define MAXM 10
#define INF ((int) 1e9)
using namespace std;
typedef pair<int, int> pii;

int n, m, K, W;
char MAP[MAXK + 10][MAXN + 5][MAXM + 5];
long long ans;
vector<pii> vec;

bool vis[MAXK + 10];
int dis[MAXK + 10], from[MAXK + 10];

int diff(int a, int b) {
    int ret = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
        ret += (MAP[a][i][j] != MAP[b][i][j] ? 1 : 0);
    return ret;
}

void prim(int S) {
    ans += n * m; vec.push_back({S, 0});
    for (int k = 1; k <= K; k++) if (!vis[k]) dis[k] = INF;

    while (true) {
        vis[S] = true;
        for (int k = 1; k <= K; k++) if (!vis[k]) {
            int d = diff(k, S) * W;
            if (dis[k] > d) dis[k] = d, from[k] = S;
        }

        S = -1;
        for (int k = 1; k <= K; k++) if (!vis[k]) {
            if (S == -1 || dis[S] > dis[k]) S = k;
        }
        if (S == -1 || dis[S] >= n * m) break;
        ans += dis[S];
        vec.push_back({S, from[S]});
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &K, &W);
    for (int k = 1; k <= K; k++) for (int i = 1; i <= n; i++) scanf("%s", MAP[k][i] + 1);
    for (int k = 1; k <= K; k++) if (!vis[k]) prim(k);
    printf("%lld\n", ans);
    for (pii p : vec) printf("%d %d\n", p.first, p.second);
    return 0;
}

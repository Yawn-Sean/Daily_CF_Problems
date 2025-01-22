#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int n, m, q;
long long PX[MAXN + 5], PY[MAXN + 5], CR[MAXN + 5], CX[MAXN + 5], CY[MAXN + 5];

int bel[MAXN + 5];
vector<int> e[MAXN + 5];
bool vis[MAXN + 5];
int dis[MAXN + 5][MAXN + 5];

void dfs(int sn, int fa, int d, int *dis) {
    dis[sn] = d;
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1, dis);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &PX[i], &PY[i]);
    for (int i = 1; i <= m; i++) scanf("%lld%lld%lld", &CR[i], &CX[i], &CY[i]);

    vector<int> ord;
    for (int i = 1; i <= m; i++) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int a, int b) {
        return CR[a] < CR[b];
    });
    for (int i = 0; i < ord.size(); i++) for (int j = 0; j < i; j++) if (!vis[ord[j]]) {
        long long u = 1LL * (CX[ord[i]] - CX[ord[j]]) * (CX[ord[i]] - CX[ord[j]]) + 1LL * (CY[ord[i]] - CY[ord[j]]) * (CY[ord[i]] - CY[ord[j]]);
        long long v = 1LL * (CR[ord[i]] - CR[ord[j]]) * (CR[ord[i]] - CR[ord[j]]);
        if (u < v) {
            e[ord[i]].push_back(ord[j]);
            e[ord[j]].push_back(ord[i]);
            vis[ord[j]] = true;
        }
    }
    for (int i = 1; i <= m; i++) if (!vis[i]) {
        e[0].push_back(i);
        e[i].push_back(0);
    }

    for (int i = 1; i <= n; i++) for (int j = 0; j < ord.size(); j++) {
        long long u = 1LL * (PX[i] - CX[ord[j]]) * (PX[i] - CX[ord[j]]) + 1LL * (PY[i] - CY[ord[j]]) * (PY[i] - CY[ord[j]]);
        long long v = 1LL * CR[ord[j]] * CR[ord[j]];
        if (u < v) { bel[i] = ord[j]; break; }
    }

    for (int i = 0; i <= m; i++) dfs(i, -1, 0, dis[i]);
    while (q--) {
        int a, b; scanf("%d%d", &a, &b);
        printf("%d\n", dis[bel[a]][bel[b]]);
    }
    return 0;
}

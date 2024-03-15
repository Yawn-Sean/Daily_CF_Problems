#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;
typedef pair<int, int> pii;

int n, q;
long long ans[MAXN + 10];
vector<pii> OP[MAXN + 10];

vector<int> e[MAXN + 10];
long long f[MAXN + 10];

void dfs(int sn, int fa, int d, long long now) {
    for (auto &p : OP[sn]) {
        f[d] += p.second;
        f[min(n + 1, d + p.first + 1)] -= p.second;
    }
    now += f[d];

    ans[sn] = now;
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1, now);

    for (auto &p : OP[sn]) {
        f[d] -= p.second;
        f[min(n + 1, d + p.first + 1)] += p.second;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        OP[x].push_back(pii(y, z));
    }

    dfs(1, 0, 1, 0);
    for (int i = 1; i <= n; i++) printf("%lld%c", ans[i], "\n "[i < n]);
    return 0;
}

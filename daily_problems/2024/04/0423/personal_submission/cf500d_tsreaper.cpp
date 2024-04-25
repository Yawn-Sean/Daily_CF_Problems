#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q;

struct Edge {
    int fn, val, nxt;
    long long cnt;
};
vector<Edge> e;
int p[MAXN + 10], sz[MAXN + 10];

void adde(int sn, int fn, int val) {
    int idx = e.size();
    e.push_back({fn, val, p[sn], 0}); p[sn] = idx;
    idx = e.size();
    e.push_back({sn, val, p[fn], 0}); p[fn] = idx;
}

long long calc(int x, int y) {
    return 1LL * x * (x - 1) / 2 * y;
}

int dfs(int sn, int fa) {
    sz[sn] = 1;
    for (int i = p[sn]; i >= 0; i = e[i].nxt) {
        int fn = e[i].fn;
        if (fn == fa) continue;
        sz[sn] += dfs(fn, sn);
        e[i].cnt = e[i ^ 1].cnt = calc(sz[fn], n - sz[fn]) + calc(n - sz[fn], sz[fn]);
    }
    return sz[sn];
}

int main() {
    scanf("%d", &n);
    memset(p, -1, sizeof(int) * (n + 3));
    for (int i = 1; i < n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        adde(x, y, z);
    }
    dfs(1, 0);

    __int128 ans = 0;
    for (int i = 0; i < e.size(); i += 2) ans += e[i].val * e[i].cnt * 2;
    scanf("%d", &q);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y); x--;
        ans -= e[x * 2].val * e[x * 2].cnt * 2;
        e[x * 2].val = e[x * 2 + 1].val = y;
        ans += e[x * 2].val * e[x * 2].cnt * 2;
        printf("%.12Lf\n", ((long double) 1) * ans / (1LL * n * (n - 1) * (n - 2) / 6));
    }
    return 0;
}

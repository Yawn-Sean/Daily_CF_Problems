#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n;
vector<int> ans;

struct Edge {
    int fn, nxt;
};
Edge e[MAXN * 2 + 10];
int p[MAXN + 10];

void adde(int sn, int fn, int idx) {
    e[idx * 2] = { fn, p[sn] }; p[sn] = idx * 2;
    e[idx * 2 + 1] = { sn, p[fn] }; p[fn] = idx * 2 + 1;
}

int dfs(int sn, int from) {
    int sz = 1;
    for (int i = p[sn]; i; i = e[i].nxt) if (i / 2 != from / 2) sz += dfs(e[i].fn, i);
    if (sz % 3 == 0 && from > 0) ans.push_back(from / 2);
    return sz;
}

void solve() {
    scanf("%d", &n);
    memset(p, 0, sizeof(int) * (n + 3));
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        adde(x, y, i);
    }

    if (n % 3) { printf("-1\n"); return; }
    ans.clear();
    dfs(1, 0);
    if (ans.size() != n / 3 - 1) { printf("-1\n"); return; }
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    printf("\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

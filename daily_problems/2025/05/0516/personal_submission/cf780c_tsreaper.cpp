#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, ans[MAXN + 5];

vector<int> e[MAXN + 5];
int deg[MAXN + 5];
bool used[MAXN + 5];

void dfs(int sn, int fa) {
    used[ans[sn]] = true;
    for (int fn : e[sn]) if (ans[fn]) used[ans[fn]] = true;

    int now = 1;
    for (int fn : e[sn]) if (!ans[fn]) {
        while (used[now]) now++;
        ans[fn] = now++;
    }

    used[ans[sn]] = false;
    for (int fn : e[sn]) used[ans[fn]] = false;

    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
        deg[x]++; deg[y]++;
    }

    for (int i = 1; i <= n; i++) m = max(m, deg[i]);
    m++;
    ans[1] = 1; dfs(1, 0);

    printf("%d\n", m);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}

#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, A[MAXN + 10];
vector<int> ans;

vector<int> e[MAXN + 10];
bool flag[MAXN + 10], root[MAXN + 10];

void dfs(int sn, int who) {
    if (flag[sn]) who = sn;
    if (A[sn] != who) { printf("-1\n"); exit(0); }
    for (int fn : e[sn]) dfs(fn, who);
    if (flag[sn]) ans.push_back(sn);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) root[i] = true;
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y);
        root[y] = false;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), flag[A[i]] = true;

    for (int i = 1; i <= n; i++) if (root[i]) dfs(i, -1);
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d\n", x);
    return 0;
}

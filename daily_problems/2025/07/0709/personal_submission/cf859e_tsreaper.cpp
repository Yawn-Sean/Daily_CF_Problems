#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
long long ans;

vector<int> e[MAXN * 2 + 5], E[MAXN * 2 + 5];
int vis[MAXN * 2 + 5];

int bfs(int S) {
    queue<int> q;
    q.push(S); vis[S] = 1;
    int ret = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        ret++;
        for (int fn : E[sn]) if (!vis[fn]) q.push(fn), vis[fn] = 1;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y);
        E[x].push_back(y); E[y].push_back(x);
    }

    ans = 1;
    for (int i = 1; i <= n * 2; i++) if (!vis[i]) {
        int sz = bfs(i), now = i;
        while (true) {
            if (vis[now] == 2) {
                if (e[now][0] == now) sz = 1;
                else sz = 2;
                break;
            }
            vis[now] = 2;
            if (e[now].empty()) break;
            now = e[now][0];
        }
        ans = ans * sz % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}

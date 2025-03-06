#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, m, K, S, T;
bool flag[MAXN + 5];

vector<int> e[MAXN + 5];
int dis[MAXN + 5];
bool vis[MAXN + 5];

bool check(int lim) {
    memset(dis, -1, sizeof(int) * (n + 3));
    queue<int> q;
    for (int i = 1; i <= n; i++) if (flag[i]) q.push(i), dis[i] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (dis[fn] < 0) q.push(fn), dis[fn] = dis[sn] + 1;
    }

    memset(vis, 0, sizeof(bool) * (n + 3));
    q.push(S); vis[S] = true;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (!vis[fn]) {
            bool ok = false;
            if (lim % 2 == 1) {
                if (dis[fn] <= lim / 2) ok = true;
            } else {
                if (dis[sn] == lim / 2) { if (dis[fn] < lim / 2) ok = true; }
                else if (dis[fn] <= lim / 2) ok = true;
            }
            if (ok) q.push(fn), vis[fn] = true;
        }
    }
    return vis[T];
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= K; i++) {
        int x; scanf("%d", &x);
        flag[x] = true;
    }
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    scanf("%d%d", &S, &T);
    flag[T] = true;

    if (!check(n)) { printf("-1\n"); return 0; }
    int head = 1, tail = n;
    while (head < tail) {
        int mid = (head + tail) >> 1;
        if (check(mid)) tail = mid;
        else head = mid + 1;
    }
    printf("%d\n", head);
    return 0;
}

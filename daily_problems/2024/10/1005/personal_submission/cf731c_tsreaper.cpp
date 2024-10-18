#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, K, ans, A[MAXN + 10];

vector<int> e[MAXN + 10];
bool vis[MAXN + 10];

void bfs(int S) {
    unordered_map<int, int> mp;
    queue<int> q;
    q.push(S); vis[S] = true;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        mp[A[sn]]++;
        for (int fn : e[sn]) if (!vis[fn]) {
            q.push(fn);
            vis[fn] = true;
        }
    }
    int mx = 0, who = 0;
    for (auto &p : mp) if (p.second > mx) mx = p.second, who = p.first;
    for (auto &p : mp) if (p.first != who) ans += p.second;
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) bfs(i);
    printf("%d\n", ans);
    return 0;
}

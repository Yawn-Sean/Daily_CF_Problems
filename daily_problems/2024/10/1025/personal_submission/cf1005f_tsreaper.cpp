#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXM ((int) 2e5)
using namespace std;

int n, m, K;
vector<string> ans;

vector<int> e[MAXN + 10], v[MAXN + 10];
int dis[MAXN + 10];
bool used[MAXM + 10];

void bfs() {
    memset(dis, -1, sizeof(int) * (n + 3));
    queue<int> q;
    q.push(1); dis[1] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (dis[fn] < 0)
            q.push(fn), dis[fn] = dis[sn] + 1;
    }
}

void dfs(int sn) {
    if (sn > n) {
        string s;
        for (int i = 1; i <= m; i++) s.push_back(used[i] ? '1' : '0');
        ans.push_back(s);
        return;
    }

    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        if (dis[fn] == dis[sn] - 1) {
            used[v[sn][i]] = true;
            dfs(sn + 1);
            used[v[sn][i]] = false;
            if (ans.size() == K) return;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(i);
        e[y].push_back(x); v[y].push_back(i);
    }
    bfs();
    dfs(2);
    printf("%d\n", ans.size());
    for (auto &s : ans) printf("%s\n", s.c_str());
    return 0;
}

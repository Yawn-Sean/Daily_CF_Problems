#include  <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, ans[MAXN + 5];

vector<int> e[MAXN + 5], v[MAXN + 5];
int from[MAXN + 5];

vector<int> bfs(int S) {
    for (int i = 1; i <= n; i++) from[i] = -1;
    queue<int> q;
    q.push(S); from[S] = 0;

    int sn;
    while (!q.empty()) {
        sn = q.front(); q.pop();
        for (int fn : e[sn]) if (from[fn] < 0)
            q.push(fn), from[fn] = sn;
    }

    vector<int> ret;
    for (; sn != S; sn = from[sn]) ret.push_back(sn);
    ret.push_back(S);
    reverse(ret.begin(), ret.end());
    return ret;
}

void dfs(int sn, int from) {
    ans[sn] = from;
    for (int i = 0; i < e[sn].size(); i++) if (v[sn][i] != from)
        dfs(e[sn][i], v[sn][i]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); v[x].push_back(i);
        e[y].push_back(x); v[y].push_back(i);
    }

    auto vec = bfs(1);
    vec = bfs(vec.back());
    int mid = vec.size() / 2;
    dfs(vec[mid], -1);
    if (vec.size() % 2 == 0) ans[vec[mid]] = ans[vec[mid - 1]];

    int t = vec.size();
    t = (t - 1) / 2;
    printf("%d\n", t);
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
    return 0;
}

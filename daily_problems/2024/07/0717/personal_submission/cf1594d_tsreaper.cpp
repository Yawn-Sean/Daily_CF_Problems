#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;
typedef pair<int, int> pii;

int n, m, ans;

vector<int> e[MAXN + 10], v[MAXN + 10];
int col[MAXN + 10];

pii bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 2;
    int cnt[2] = {0};
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        cnt[col[sn] - 2]++;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i], val = col[sn] ^ v[sn][i];
            if (col[fn] > 0) {
                if (col[fn] != val) return {-1, -1};
                continue;
            }
            q.push(fn); col[fn] = val;
        }
    }
    return {cnt[0], cnt[1]};
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y;
        char s[10];
        scanf("%d%d%s", &x, &y, s);
        int val = (s[0] == 'i' ? 1 : 0);
        e[x].push_back(y); v[x].push_back(val);
        e[y].push_back(x); v[y].push_back(val);
    }

    ans = 0;
    memset(col, 0, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) if (col[i] == 0) {
        pii p = bfs(i);
        if (p.first < 0) { printf("-1\n"); return; }
        ans += max(p.first, p.second);
    }
    printf("%d\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

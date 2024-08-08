#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;
typedef pair<int, int> pii;

int n, m;

vector<int> e[MAXN + 10];
int col[MAXN + 10];

pii bfs(int S) {
    queue<int> q;
    q.push(S); col[S] = 1;
    pii ret = {0, 0};
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        if (col[sn] == 1) ret.first++;
        else ret.second++;
        for (int fn : e[sn]) {
            if (col[fn]) {
                if (col[fn] == col[sn]) return {-1, -1};
            } else {
                q.push(fn);
                col[fn] = 3 - col[sn];
            }
        }
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    int cnt[4] = {0};
    long long ans = 0;
    for (int i = 1; i <= n; i++) if (!col[i]) {
        pii p = bfs(i);
        if (p.first < 0) { printf("0 1\n"); return 0; }
        ans += 1LL * p.first * (p.first - 1) / 2;
        ans += 1LL * p.second * (p.second - 1) / 2;
        cnt[min(p.first + p.second, 3)]++;
    }

    if (cnt[3] > 0) printf("1 %lld\n", ans);
    else if (cnt[2] > 0) printf("2 %lld\n", 1LL * cnt[2] * (n - 2));
    else printf("3 %lld\n", 1LL * n * (n - 1) * (n - 2) / 6);
    return 0;
}

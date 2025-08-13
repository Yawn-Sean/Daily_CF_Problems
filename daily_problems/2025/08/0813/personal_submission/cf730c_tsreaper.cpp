#include <bits/stdc++.h>
#define MAXN 5000
using namespace std;
typedef pair<int, int> pii;

int n, m, W;
vector<pii> A[MAXN + 5];

vector<int> e[MAXN + 5];
int dis[MAXN + 5];
vector<int> city[MAXN + 5];

void bfs(int S) {
    for (int i = 1; i <= n; i++) dis[i] = -1;
    queue<int> q;
    q.push(S); dis[S] = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int fn : e[sn]) if (dis[fn] < 0)
            q.push(fn), dis[fn] = dis[sn] + 1;
    }
}

void solve() {
    int x, y, z; scanf("%d%d%d", &x, &y, &z);
    bfs(x);
    for (int i = 0; i <= n; i++) city[i].clear();
    for (int i = 1; i <= n; i++) if (dis[i] >= 0) city[dis[i]].push_back(i);

    priority_queue<pii> pq;
    long long cost = 0, cnt = 0;
    for (int i = 0; i <= n; i++) {
        for (int c : city[i]) for (pii p : A[c]) {
            pq.push(p);
            cost += 1LL * p.first * p.second;
            cnt += p.second;
        }
        while (!pq.empty() && cnt - pq.top().second >= y) {
            pii p = pq.top(); pq.pop();
            cost -= 1LL * p.first * p.second;
            cnt -= p.second;
        }
        if (cnt >= y) {
            int det = cnt - y;
            long long tmp = cost - 1LL * pq.top().first * det;
            if (tmp <= z) { printf("%d\n", i); return; }
        }
    }
    printf("-1\n");
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    scanf("%d", &W);
    for (int i = 1; i <= W; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        A[x].push_back({z, y});
    }
    
    int q; scanf("%d", &q);
    while (q--) solve();
    return 0;
}

#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<pii> ans;

vector<int> e[MAXN + 10];
int dis1[MAXN + 10], dis2[MAXN + 10], from[MAXN + 10];

pii bfs(int S, int *dis) {
    queue<int> q;
    q.push(S); dis[S] = 0;
    int last = S;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        last = sn;
        for (int fn : e[sn]) if (dis[fn] == -1) {
            q.push(fn);
            dis[fn] = dis[sn] + 1;
            from[fn] = sn;
        }
    }

    int now = last;
    for (int i = 1; i <= dis[last] / 2; i++) now = from[now];
    return {last, now};
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    memset(dis1, -1, sizeof(int) * (n + 3));
    memset(dis2, -1, sizeof(int) * (n + 3));
    priority_queue<pii> pq;
    for (int i = 1; i <= n; i++) if (dis1[i] == -1) {
        pii p = bfs(i, dis1);
        p = bfs(p.first, dis2);
        pq.push({dis2[p.first], p.second});
    }

    int x = pq.top().second; pq.pop();
    while (!pq.empty()) {
        int y = pq.top().second; pq.pop();
        e[x].push_back(y);
        e[y].push_back(x);
        ans.push_back({x, y});
    }

    memset(dis1, -1, sizeof(int) * (n + 3));
    memset(dis2, -1, sizeof(int) * (n + 3));
    pii p = bfs(1, dis1);
    p = bfs(p.first, dis2);
    printf("%d\n", dis2[p.first]);
    for (pii p : ans) printf("%d %d\n", p.first, p.second);
    return 0;
}

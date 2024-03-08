#include <bits/stdc++.h>
#define MAXN ((int) 4e5)
#define MAXPROD ((int) 4e5)
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;

int n, m, C[MAXN + 10];
vector<int> A[MAXN + 10];

vector<int> e[MAXPROD + MAXN + 10];
vector<long long> v[MAXPROD + MAXN + 10];
long long dis[MAXPROD + MAXN + 10];

int idx(int i, int j) {
    return (i - 1) * m + j;
}

void unidx(int idx, int &i, int &j) {
    idx--;
    i = idx / m + 1;
    j = idx % m + 1;
}

long long dijkstra() {
    memset(dis, -1, sizeof(long long) * (n * m + n + 3));
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int j = 1; j <= m; j++) pq.push(pli(0, idx(1, j)));
    while (!pq.empty()) {
        pli p = pq.top(); pq.pop();
        int sn = p.second;
        if (dis[sn] >= 0) continue;
        dis[sn] = p.first;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            if (dis[fn] >= 0) continue;
            pq.push(pli(dis[sn] + v[sn][i], fn));
        }
    }

    long long ret = 1e18;
    for (int j = 1; j <= m; j++) if (dis[idx(n, j)] >= 0) ret = min(ret, dis[idx(n, j)]);
    return ret;
}

void solve() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &C[i]);
    C[1] = 0;
    for (int i = 1; i <= n; i++) {
        A[i].clear();
        A[i].push_back(0);
        for (int j = 1; j <= m; j++) {
            int x; scanf("%d", &x);
            A[i].push_back(x);
        }
    }

    for (int i = 1; i <= n * m + n; i++) e[i].clear(), v[i].clear();
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int x = idx(i, j), y = n * m + i;
        e[x].push_back(y); v[x].push_back(C[i]);
        e[y].push_back(x); v[y].push_back(0);
    }
    for (int j = 1; j <= m; j++) {
        vector<pii> vec;
        for (int i = 1; i <= n; i++) vec.push_back(pii(A[i][j], i));
        sort(vec.begin(), vec.end());
        for (int i = 1; i < n; i++) {
            int x = vec[i - 1].second, y = vec[i].second;
            int ix = idx(x, j), iy = idx(y, j);
            long long vx = vec[i - 1].first, vy = vec[i].first;
            e[ix].push_back(iy); v[ix].push_back(0);
            e[iy].push_back(ix); v[iy].push_back(vy - vx);
        }
    }

    printf("%lld\n", dijkstra() + C[n]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

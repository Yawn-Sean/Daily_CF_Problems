#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<long long, int> pli;

int n, m, K;

vector<int> e[MAXN + 5], v[MAXN + 5];
long long dis[MAXN + 5];

int main() {
    scanf("%d%d%d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        e[x].push_back(y); v[x].push_back(z);
        e[y].push_back(x); v[y].push_back(z);
    }

    vector<int> vec;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[1] = 0; pq.push({0, 1});
    while (!pq.empty()) {
        pli p = pq.top(); pq.pop();
        int sn = p.second;
        if (dis[sn] != p.first) continue;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            if (sn < fn) vec.push_back(v[sn][i]);
            if (dis[fn] > dis[sn] + v[sn][i])
                dis[fn] = dis[sn] + v[sn][i], pq.push({dis[fn], fn});
        }
    }

    sort(vec.begin(), vec.end());
    long long sm = 0;
    for (int i = 0; i < K && i < vec.size(); i++) sm += vec[i];
    printf("%lld\n", min(dis[n], sm));
    return 0;
}

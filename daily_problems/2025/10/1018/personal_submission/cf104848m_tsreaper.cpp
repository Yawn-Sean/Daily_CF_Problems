#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;
typedef pair<double, int> pdi;

int n, m, T;

vector<int> e[MAXN + 5];
vector<double> v[MAXN + 5];
double dis[MAXN + 5];

void dijkstra() {
    for (int i = 1; i <= n; i++) dis[i] = 1e200;
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    pq.push({0, 1}); dis[1] = 0;
    while (!pq.empty()) {
        pdi p = pq.top(); pq.pop();
        int sn = p.second;
        if (dis[sn] != p.first) continue;
        for (int i = 0; i < e[sn].size(); i++) {
            int fn = e[sn][i];
            double d = dis[sn] + v[sn][i];
            if (dis[fn] > d) pq.push({d, fn}), dis[fn] = d;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 1; i <= m; i++) {
        int x, y, a, b; scanf("%d%d%d%d", &x, &y, &a, &b);
        double t = sqrt(1LL * a * b);
        e[x].push_back(y); v[x].push_back(t);
        e[y].push_back(x); v[y].push_back(t);
    }
    dijkstra();
    printf("%.12f\n", dis[n] / T * dis[n]);
    return 0;
}

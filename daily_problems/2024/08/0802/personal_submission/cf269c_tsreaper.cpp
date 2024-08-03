#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m;

struct Edge {
    int fn, val, nxt, dir;
};
vector<Edge> e;
int p[MAXN + 10];
long long tot[MAXN + 10];

void adde(int sn, int fn, int val) {
    int idx = e.size();
    e.push_back({fn, val, p[sn], 0});
    p[sn] = idx;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(p, -1, sizeof(int) * (n + 3));
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        adde(x, y, z); adde(y, x, z);
        tot[x] += z; tot[y] += z;
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        for (int i = p[sn]; i >= 0; i = e[i].nxt) if (e[i].dir == 0) {
            e[i].dir = 1; e[i ^ 1].dir = -1;
            int fn = e[i].fn;
            tot[fn] -= e[i].val * 2;
            if (fn != n && tot[fn] == 0) q.push(fn);
        }
    }

    for (int i = 0; i < e.size(); i += 2) {
        if (e[i].dir == 1) printf("0\n");
        else printf("1\n");
    }
    return 0;
}

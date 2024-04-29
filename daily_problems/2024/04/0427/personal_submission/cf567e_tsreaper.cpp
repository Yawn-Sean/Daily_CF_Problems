#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD 1001001011
using namespace std;
typedef pair<long long, int> pli;

int n, m, S, T;

struct Edge {
    int fn, val, nxt;
};
vector<Edge> e, E;
int p[MAXN + 10], P[MAXN + 10];

long long d[MAXN + 10], D[MAXN + 10];
long long f[MAXN + 10], F[MAXN + 10];

void adde(int sn, int fn, int val, vector<Edge> &e, int *p) {
    int idx = e.size();
    e.push_back({fn, val, p[sn]}); p[sn] = idx;
}

void gao(int S, vector<Edge> &e, int *p, long long *d, long long *f) {
    memset(d, -1, sizeof(long long) * (n + 3));
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, S});
    while (!pq.empty()) {
        pli tp = pq.top(); pq.pop();
        int sn = tp.second;
        if (d[sn] >= 0) continue;
        d[sn] = tp.first;
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (d[fn] >= 0) continue;
            pq.push(pli(d[sn] + e[i].val, fn));
        }
    }

    vector<pli> vec;
    for (int i = 1; i <= n; i++) if (d[i] >= 0) vec.push_back(pli(d[i], i));
    sort(vec.begin(), vec.end());
    f[S] = 1;
    for (pli tp : vec) {
        int sn = tp.second;
        for (int i = p[sn]; i >= 0; i = e[i].nxt) {
            int fn = e[i].fn;
            if (d[fn] != d[sn] + e[i].val) continue;
            f[fn] = (f[fn] + f[sn]) % MOD;
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &S, &T);
    memset(p, -1, sizeof(int) * (n + 3)); memset(P, -1, sizeof(int) * (n + 3));
    for (int i = 1; i <= m; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        adde(x, y, z, e, p); adde(y, x, z, E, P);
    }
    gao(S, e, p, d, f); gao(T, E, P, D, F);

    for (int i = 0; i < m; i++) {
        int sn = E[i].fn, fn = e[i].fn, val = e[i].val;
        if (d[sn] < 0 || D[fn] < 0) { printf("NO\n"); continue; }
        long long delta = d[sn] + val + D[fn] - d[T];
        if (delta == 0) {
            if (f[sn] * F[fn] % MOD == f[T]) printf("YES\n");
            else if (val > 1) printf("CAN 1\n");
            else printf("NO\n");
        } else {
            if (delta + 1 < val) printf("CAN %lld\n", delta + 1);
            else printf("NO\n");
        }
    }
    return 0;
}

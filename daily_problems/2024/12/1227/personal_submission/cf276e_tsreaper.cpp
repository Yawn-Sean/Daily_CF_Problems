#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q;

vector<int> e[MAXN + 5];
int bel[MAXN + 5], dep[MAXN + 5], lim[MAXN + 5];

vector<long long> tree[MAXN + 5];
long long X;

int lb(int x) { return x & (-x); }

void add(int tid, int pos, int val) {
    if (pos > lim[tid]) return;
    for (; pos <= lim[tid]; pos += lb(pos)) tree[tid][pos] += val;
}

long long query(int tid, int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[tid][pos];
    return ret;
}

void dfs(int sn, int fa, int d) {
    if (fa == 1) bel[sn] = sn;
    else if (fa > 1) bel[sn] = bel[fa];
    dep[sn] = d;
    for (int fn : e[sn]) if (fn != fa) dfs(fn, sn, d + 1);
    if (e[sn].size() == 1) {
        lim[bel[sn]] = d;
        tree[bel[sn]].resize(d + 1);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }
    dfs(1, 0, 0);
    lim[0] = n; tree[0].resize(n + 1);

    while (q--) {
        int op; scanf("%d", &op);
        if (op == 0) {
            int v, x, d; scanf("%d%d%d", &v, &x, &d);
            if (v == 1) {
                X += x;
                add(0, 1, x); add(0, d + 1, -x);
            } else if (d < dep[v]) {
                add(bel[v], dep[v] - d, x); add(bel[v], dep[v] + d + 1, -x);
            } else {
                X += x;
                add(bel[v], 1, x); add(bel[v], dep[v] + d + 1, -x);
                int rem = d - dep[v];
                if (rem > 0) {
                    add(bel[v], 1, -x); add(bel[v], rem + 1, x);
                    add(0, 1, x); add(0, rem + 1, -x);
                }
            }
        } else {
            int v; scanf("%d", &v);
            if (v == 1) printf("%lld\n", X);
            else printf("%lld\n", query(0, dep[v]) + query(bel[v], dep[v]));
        }
    }
    return 0;
}

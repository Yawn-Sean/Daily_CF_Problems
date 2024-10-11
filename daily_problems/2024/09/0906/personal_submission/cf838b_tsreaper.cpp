#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((long long) 1e18)
using namespace std;

int n, q, E[MAXN * 2 + 10][3];

vector<int> e[MAXN + 10], v[MAXN + 10];
int clk, dfn[MAXN + 10], bgn[MAXN + 10], fin[MAXN + 10];
long long dis[MAXN + 10];

struct Node {
    long long mn, lazy;
};
Node tree[2][MAXN * 4 + 10];

void dfs(int sn) {
    bgn[sn] = ++clk; dfn[clk] = sn;
    for (int i = 0; i < e[sn].size(); i++) {
        int fn = e[sn][i];
        dis[fn] = dis[sn] + v[sn][i];
        dfs(fn);
    }
    fin[sn] = clk;
}

Node merge(Node &nl, Node &nr) {
    return {min(nl.mn, nr.mn), 0};
}

void build(Node *tree, int id, int l, int r) {
    if (l == r) tree[id] = {dis[dfn[l]], 0};
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        build(tree, nxt, l, mid); build(tree, nxt | 1, mid + 1, r);
        tree[id] = merge(tree[nxt], tree[nxt | 1]);
    }
}

void down(Node *tree, int id) {
    if (tree[id].lazy == 0) return;
    int nxt = id << 1;
    tree[nxt].mn += tree[id].lazy; tree[nxt].lazy += tree[id].lazy;
    tree[nxt | 1].mn += tree[id].lazy; tree[nxt | 1].lazy += tree[id].lazy;
    tree[id].lazy = 0;
}

void add(Node *tree, int id, int l, int r, int ql, int qr, int qv) {
    if (ql <= l && r <= qr) tree[id].mn += qv, tree[id].lazy += qv;
    else {
        down(tree, id);
        int nxt = id << 1, mid = (l + r) >> 1;
        if (ql <= mid) add(tree, nxt, l, mid, ql, qr, qv);
        if (qr > mid) add(tree, nxt | 1, mid + 1, r, ql, qr, qv);
        tree[id] = merge(tree[nxt], tree[nxt | 1]);
    }
}

long long query(Node *tree, int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[id].mn;
    down(tree, id);
    int nxt = id << 1, mid = (l + r) >> 1;
    return min(
        ql <= mid ? query(tree, nxt, l, mid, ql, qr) : INF,
        qr > mid ? query(tree, nxt | 1, mid + 1, r, ql, qr) : INF
    );
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) scanf("%d", &E[i][j]);
        e[E[i][0]].push_back(E[i][1]);
        v[E[i][0]].push_back(E[i][2]);
    }
    dfs(1);
    for (int i = 0; i < 2; i++) build(tree[i], 1, 1, n);

    for (int i = n; i < n * 2 - 1; i++) {
        for (int j = 0; j < 3; j++) scanf("%d", &E[i][j]);
        add(tree[1], 1, 1, n, bgn[E[i][0]], bgn[E[i][0]], E[i][2]);
    }

    while (q--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if (op == 1) {
            if (x < n) {
                int fn = E[x][1];
                for (int i = 0; i < 2; i++) add(tree[i], 1, 1, n, bgn[fn], fin[fn], y - E[x][2]);
            } else {
                int fn = E[x][0];
                add(tree[1], 1, 1, n, bgn[fn], bgn[fn], y - E[x][2]);
            }
            E[x][2] = y;
        } else {
            if (bgn[x] <= bgn[y] && bgn[y] <= fin[x]) printf("%lld\n", query(tree[0], 1, 1, n, bgn[y], bgn[y]) - query(tree[0], 1, 1, n, bgn[x], bgn[x]));
            else printf("%lld\n", query(tree[1], 1, 1, n, bgn[x], fin[x]) - query(tree[0], 1, 1, n, bgn[x], bgn[x]) + query(tree[0], 1, 1, n, bgn[y], bgn[y]));
        }
    }
    return 0;
}

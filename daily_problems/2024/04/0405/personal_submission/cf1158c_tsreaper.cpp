#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, ans[MAXN + 10];

vector<int> e[MAXN * 4 + 10];
int deg[MAXN * 4 + 10];
int which[MAXN + 10], L[MAXN * 4 + 10], R[MAXN * 4 + 10];

void adde(int x, int y) {
    e[x].push_back(y);
    deg[y]++;
}

void build(int id, int l, int r) {
    L[id] = l; R[id] = r;
    if (l == r) which[l] = id;
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        build(nxt, l, mid); adde(nxt, id);
        build(nxt | 1, mid + 1, r); adde(nxt | 1, id);
    }
}

void modify(int id, int l, int r, int ql, int qr, int qv) {
    if (ql <= l && r <= qr) adde(id, qv);
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        if (ql <= mid) modify(nxt, l, mid, ql, qr, qv);
        if (qr > mid) modify(nxt | 1, mid + 1, r, ql, qr, qv);
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n * 4; i++) e[i].clear(), deg[i] = 0, L[i] = R[i] = 0;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (x == -1) continue;
        if (x <= n) adde(which[i], which[x]);
        if (i + 1 <= x - 1) modify(1, 1, n, i + 1, x - 1, which[i]);
    }

    queue<int> q;
    for (int i = 1; i <= n * 4; i++) if (L[i] > 0 && deg[i] == 0) q.push(i);
    int now = 0;
    while (!q.empty()) {
        int sn = q.front(); q.pop();
        if (L[sn] == R[sn]) ans[L[sn]] = ++now;
        for (int fn : e[sn]) {
            deg[fn]--;
            if (deg[fn] == 0) q.push(fn);
        }
    }

    for (int i = 1; i <= n * 4; i++) if (deg[i] > 0) { printf("-1\n"); return; }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], "\n "[i < n]);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

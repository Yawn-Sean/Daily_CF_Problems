#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, q, A[MAXN + 5];

struct Node {
    int l, r;
    long long ans, l1, r1, l2, r2;

    void apply(int pos, int x) {
        l = r = pos;
        ans = 0;
        l1 = x - 1; r1 = -x;
        l2 = -x - 1; r2 = x;
    }
} tree[MAXN * 4 + 5];

Node merge(Node nl, Node nr) {
    return Node {
        nl.l,
        nr.r,
        max({nl.ans, nr.ans, nl.l1 + nr.r1, nl.l2 + nr.r2}),
        max(nr.l1, nl.l1 - (nr.r - nr.l + 1)),
        max(nl.r1, nr.r1 - (nl.r - nl.l + 1)),
        max(nr.l2, nl.l2 - (nr.r - nr.l + 1)),
        max(nl.r2, nr.r2 - (nl.r - nl.l + 1))
    };
}

void build(int id, int l, int r) {
    if (l == r) tree[id].apply(l, A[l]);
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        build(nxt, l, mid); build(nxt | 1, mid + 1, r);
        tree[id] = merge(tree[nxt], tree[nxt | 1]);
    }
}

void modify(int id, int l, int r, int qpos, int qv) {
    if (l == r) tree[id].apply(l, qv);
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        if (qpos <= mid) modify(nxt, l, mid, qpos, qv);
        else modify(nxt | 1, mid + 1, r, qpos, qv);
        tree[id] = merge(tree[nxt], tree[nxt | 1]);
    }
}

void solve() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);

    build(1, 1, n);
    printf("%lld\n", tree[1].ans);

    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        modify(1, 1, n, x, y);
        printf("%lld\n", tree[1].ans);
    }
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

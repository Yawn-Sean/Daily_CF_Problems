#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
using namespace std;

int n, q, A[MAXN + 5];

struct Node {
    int l, r;
    long long v[30];

    void apply(int pos, int x) {
        l = r = pos;
        for (int i = 2, idx = 0; i <= 6; i++) {
            for (int j = 1; j <= i; j++, idx++) v[idx] = 1LL * x * j;
            for (int j = i - 1; j >= 2; j--, idx++) v[idx] = 1LL * x * j;
        }
    }
} tree[MAXN * 4 + 5];

Node merge(Node nl, Node nr) {
    Node ret;
    ret.l = nl.l; ret.r = nr.r;
    int half = nl.r - nl.l + 1;
    for (int i = 2, base = 0; i <= 6; i++) {
        for (int j = 0, bias = half; j < (i - 1) * 2; j++, bias++) {
            ret.v[base + j] = nl.v[base + j] + nr.v[base + bias % ((i - 1) * 2)];
        }
        base += (i - 1) * 2;
    }
    return ret;
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

Node query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[id];
    int nxt = id << 1, mid = (l + r) >> 1;
    if (qr <= mid) return query(nxt, l, mid, ql, qr);
    if (ql > mid) return query(nxt | 1, mid + 1, r, ql, qr);
    return merge(query(nxt, l, mid, ql, qr), query(nxt | 1, mid + 1, r, ql, qr));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    build(1, 1, n);

    scanf("%d", &q);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int x, y; scanf("%d%d", &x, &y);
            modify(1, 1, n, x, y);
        } else {
            int l, r, z; scanf("%d%d%d", &l, &r, &z);
            Node node = query(1, 1, n, l, r);
            int idx = (z - 1) * (z - 2);
            printf("%lld\n", node.v[idx]);
        }
    }
    return 0;
}

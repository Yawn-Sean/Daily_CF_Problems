#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, q;

int tree[MAXN * 4 + 5];

void modify(int id, int l, int r, int qpos, int qv) {
    if (l == r) tree[id] = max(tree[id], qv);
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        if (qpos <= mid) modify(nxt, l, mid, qpos, qv);
        else modify(nxt | 1, mid + 1, r, qpos, qv);
        tree[id] = min(tree[nxt], tree[nxt | 1]);
    }
}

int find(int id, int l, int r, int ql, int qr, int qv) {
    if (tree[id] >= qv) return 0;
    if (l == r) return l;
    int nxt = id << 1, mid = (l + r) >> 1;
    if (qr <= mid) return find(nxt, l, mid, ql, qr, qv);
    if (ql > mid) return find(nxt | 1, mid + 1, r, ql, qr, qv);
    int t = find(nxt | 1, mid + 1, r, ql, qr, qv);
    if (t == 0) t = find(nxt, l, mid, ql, qr, qv);
    return t;
}

int main() {
    scanf("%d%d", &n, &q);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int l, r; scanf("%d%d", &l, &r);
            modify(1, 1, n, l, r);
        } else {
            int x; scanf("%d", &x);
            int t = find(1, 1, n, 1, x, x);
            printf("%d\n", x - t + 1);
        }
    }
    return 0;
}

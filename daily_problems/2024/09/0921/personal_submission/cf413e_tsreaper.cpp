#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define INF ((int) 1e9)
using namespace std;
typedef array<array<long long, 2>, 2> a22;

int n, q;
char MAP[2][MAXN + 10];

a22 f[MAXN * 4 + 10];

a22 merge(a22 a, a22 b) {
    a22 ret;
    for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) {
        ret[x][y] = INF;
        for (int z = 0; z < 2; z++) ret[x][y] = min(ret[x][y], a[x][z] + b[z][y] + 1);
    }
    return ret;
}

void build(int id, int l, int r) {
    if (l == r) {
        for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) {
            if (MAP[x][l] == 'X' || MAP[y][l] == 'X') f[id][x][y] = INF;
            else f[id][x][y] = abs(x - y);
        }
    } else {
        int nxt = id << 1, mid = (l + r) >> 1;
        build(nxt, l, mid); build(nxt | 1, mid + 1, r);
        f[id] = merge(f[nxt], f[nxt | 1]);
    }
}

a22 query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return f[id];
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        if (qr <= mid) return query(nxt, l, mid, ql, qr);
        else if (ql > mid) return query(nxt | 1, mid + 1, r, ql, qr);
        else return merge(query(nxt, l, mid, ql, qr), query(nxt | 1, mid + 1, r, ql, qr));
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < 2; i++) scanf("%s", MAP[i] + 1);

    build(1, 1, n);
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        x--; y--;
        int r1 = x / n, c1 = x % n + 1, r2 = y / n, c2 = y % n + 1;
        if (c1 > c2) swap(r1, r2), swap(c1, c2);
        long long t = query(1, 1, n, c1, c2)[r1][r2];
        if (t < INF) printf("%lld\n", t);
        else printf("-1\n");
    }
    return 0;
}

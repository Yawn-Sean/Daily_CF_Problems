#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define INF ((long long) 1e18)
using namespace std;

int n, D, ans, A[MAXN + 10];

long long f[MAXN + 10], maxo[MAXN * 4 + 10], lazy[MAXN * 4 + 10];

void build(int id, int l, int r) {
    if (l == r) maxo[id] = f[l];
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        build(nxt, l, mid); build(nxt | 1, mid + 1, r);
        maxo[id] = max(maxo[nxt], maxo[nxt | 1]);
    }
}

void down(int id) {
    if (lazy[id] == 0) return;
    int nxt = id << 1;
    maxo[nxt] += lazy[id]; lazy[nxt] += lazy[id];
    maxo[nxt | 1] += lazy[id]; lazy[nxt | 1] += lazy[id];
    lazy[id] = 0;
}

void add(int id, int l, int r, int ql, int qr, long long qv) {
    if (ql <= l && r <= qr) maxo[id] += qv, lazy[id] += qv;
    else {
        down(id);
        int nxt = id << 1, mid = (l + r) >> 1;
        if (ql <= mid) add(nxt, l, mid, ql, qr, qv);
        if (qr > mid) add(nxt | 1, mid + 1, r, ql, qr, qv);
        maxo[id] = max(maxo[nxt], maxo[nxt | 1]);
    }
}

long long query(int id, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return maxo[id];
    else {
        down(id);
        int nxt = id << 1, mid = (l + r) >> 1;
        return max(
            ql <= mid ? query(nxt, l, mid, ql, qr) : -INF,
            qr > mid ? query(nxt | 1, mid + 1, r, ql, qr) : -INF
        );
    }
}

int main() {
    scanf("%d%d", &n, &D);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        f[i] = f[i - 1] + A[i];
    }
    for (int i = 1; i <= n; i++) if (f[i] > D) { printf("-1\n"); return 0; }

    build(1, 0, n);
    for (int i = 1; i <= n; i++) if (A[i] == 0) {
        long long now = query(1, 0, n, i, i);
        if (now >= 0) continue;
        long long mx = query(1, 0, n, i - 1, n);
        long long rem = D - mx;
        if (rem < -now) { printf("-1\n"); return 0; }
        add(1, 0, n, i - 1, n, rem);
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

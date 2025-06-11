#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXX ((int) 1e6 + 7)
#define INF ((long long) 1e18)
using namespace std;
typedef pair<int, int> pii;

int n, m, K;
long long ans, A[MAXX + 10], B[MAXX + 10];

long long mx[MAXX * 4 + 10], lazy[MAXX * 4 + 10];

void build(int id, int l, int r) {
    if (l == r) mx[id] = -B[l];
    else {
        int nxt = id << 1, mid = (l + r) >> 1;
        build(nxt, l, mid); build(nxt | 1, mid + 1, r);
        mx[id] = max(mx[nxt], mx[nxt | 1]);
    }
}

void down(int id) {
    if (lazy[id] == 0) return;
    int nxt = id << 1;
    mx[nxt] += lazy[id]; lazy[nxt] += lazy[id];
    mx[nxt | 1] += lazy[id]; lazy[nxt | 1] += lazy[id];
    lazy[id] = 0;
}

void add(int id, int l, int r, int ql, int qr, int qv) {
    if (ql <= l && r <= qr) mx[id] += qv, lazy[id] += qv;
    else {
        down(id);
        int nxt = id << 1, mid = (l + r) >> 1;
        if (ql <= mid) add(nxt, l, mid, ql, qr, qv);
        if (qr > mid) add(nxt | 1, mid + 1, r, ql, qr, qv);
        mx[id] = max(mx[nxt], mx[nxt | 1]);
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &K);

    for (int i = 1; i <= MAXX; i++) A[i] = B[i] = INF;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        A[x] = min(A[x], 1LL * y);
    }
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        B[x] = min(B[x], 1LL * y);
    }
    for (int i = MAXX - 1; i > 0; i--) {
        A[i] = min(A[i], A[i + 1]);
        B[i] = min(B[i], B[i + 1]);
    }
    build(1, 1, MAXX);

    unordered_map<int, vector<pii>> mp;
    for (int i = 1; i <= K; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        mp[x + 1].push_back({y + 1, z});
    }
    ans = -INF;
    for (int i = 1; i <= MAXX; i++) {
        if (mp.count(i)) for (auto p : mp[i]) add(1, 1, MAXX, p.first, MAXX, p.second);
        ans = max(ans, mx[1] - A[i]);
    }
    printf("%lld\n", ans);
    return 0;
}

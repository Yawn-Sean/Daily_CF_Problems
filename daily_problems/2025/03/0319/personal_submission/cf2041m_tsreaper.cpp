#include <bits/stdc++.h>
#define MAXN ((int) 1e6)
using namespace std;

int n, m, A[MAXN + 5];

int tree[MAXN + 5], f[MAXN + 5], g[MAXN + 5];

int lb(int x) { return x & (-x); }

void add(int pos) {
    for (; pos <= m; pos += lb(pos)) tree[pos]++;
}

int query(int lim) {
    if (lim == 0) return 0;
    int now = 0, sm = 0;
    for (int p = __lg(m); p >= 0; p--) {
        int nxt = now | (1 << p);
        if (nxt <= m && sm + tree[nxt] < lim) now = nxt, sm += tree[nxt];
    }
    return now + 1;
}

long long gao() {
    memset(tree, 0, sizeof(int) * (m + 3));
    f[1] = 0;
    for (int i = 1; i <= n; i++) f[i] = max(f[i - 1], A[i]);
    g[n + 1] = m + 1;
    for (int i = n; i > 0; i--) g[i] = min(g[i + 1], A[i]);

    long long ret = 1e18;
    for (int i = 1, j = 1; i <= n; i++) {
        add(A[i]);
        while (j <= n) {
            int l, r;
            if (j - 1 <= i) {
                l = query(j - 1);
                r = min(query(j), g[i + 1]);
            } else {
                l = f[j - 1];
                r = g[j];
            }
            if (l > r) break;
            j++;
        }
        if (j <= n) {
            int det = n + 2 - j;
            ret = min(ret, 1LL * i * i + 1LL * det * det);
        } else {
            ret = min(ret, 1LL * i * i);
        }
    }
    return ret;
}

int main() {
    scanf("%d", &n);

    map<int, int> mp;
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]), mp[A[i]] = 1;
    for (auto &p : mp) p.second = ++m;
    for (int i = 1; i <= n; i++) A[i] = mp[A[i]];

    bool ok = true;
    for (int i = 1; i < n; i++) if (A[i] > A[i + 1]) { ok = false; break; }
    if (ok) { printf("0\n"); return 0; }

    long long ans = gao();
    for (int i = 1; i <= n; i++) A[i] = m + 1 - A[i];
    reverse(A + 1, A + n + 1);
    ans = min(ans, gao());
    printf("%lld\n", ans);
    return 0;
}

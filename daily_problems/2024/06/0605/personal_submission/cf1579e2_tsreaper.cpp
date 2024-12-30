#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
using namespace std;

int n, m, A[MAXN + 10];
long long ans;

int tree[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= m; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

void solve() {
    scanf("%d", &n);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        mp[A[i]] = 1;
    }
    m = 0;
    for (auto &p : mp) p.second = ++m;
    for (int i = 1; i <= n; i++) A[i] = mp[A[i]];

    ans = 0;
    memset(tree, 0, sizeof(int) * (m + 3));
    for (int i = 1; i <= n; i++) {
        int x = query(m) - query(A[i]), y = query(A[i] - 1);
        ans += min(x, y);
        add(A[i], 1);
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

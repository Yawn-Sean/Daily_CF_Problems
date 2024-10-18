#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, tree[MAXN + 10];

int lb(int x) { return x & (-x); }

void add(int pos, int val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] += val;
}

int query(int pos) {
    int ret = 0;
    for (; pos; pos -= lb(pos)) ret += tree[pos];
    return ret;
}

void solve() {
    scanf("%d", &n);
    memset(tree, 0, sizeof(int) * (n + 3));
    bool ok = false;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        if (query(x) - query(x - 1) > 0) ok = true;
        p ^= (query(n) - query(x)) % 2;
        add(x, 1);
    }
    if (ok || p % 2 == 0) printf("YES\n");
    else printf("NO\n");
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

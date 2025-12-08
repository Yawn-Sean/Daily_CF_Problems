#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
using namespace std;

int n, A[MAXN + 5], B[MAXN + 5];
long long ans;

int f[MAXN + 5], g[MAXN + 5], tree[MAXN + 5];
vector<int> vec[MAXN + 5];

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
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &B[i]);

    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[B[i]] = i;
        f[i] = 0;
        if (mp.count(A[i])) f[i] = mp[A[i]];
    }
    mp.clear();
    for (int i = n; i > 0; i--) {
        mp[B[i]] = i;
        g[i] = n + 1;
        if (mp.count(A[i])) g[i] = mp[A[i]];
    }

    for (int i = 1; i <= n + 1; i++) vec[i].clear();
    for (int i = 1; i <= n; i++) vec[g[i]].push_back(i);

    ans = 0;
    memset(tree, 0, sizeof(int) * (n + 3));
    for (int i = 1; i <= n; i++) {
        for (int x : vec[i]) add(x, 1);
        ans += query(i) - query(f[i]);
    }
    printf("%lld\n", ans);
}

int main() {
    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

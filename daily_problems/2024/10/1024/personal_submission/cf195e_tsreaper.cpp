#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n;
long long ans;

vector<array<int, 3>> e[MAXN + 10];
int root[MAXN + 10];
int clk, bgn[MAXN + 10], fin[MAXN + 10];
long long tree[MAXN + 10];

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void dfs(int sn) {
    bgn[sn] = ++clk;
    for (auto &arr : e[sn]) dfs(arr[0]);
    fin[sn] = clk;
}

int lb(int x) { return x & (-x); }

void add(int pos, long long val) {
    for (; pos <= n; pos += lb(pos)) tree[pos] = (tree[pos] + val) % MOD;
}

long long query(int pos) {
    long long ret = 0;
    for (; pos; pos -= lb(pos)) ret = (ret + tree[pos]) % MOD;
    return ret;
}

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        root[i] = i;
        int K; scanf("%d", &K);
        while (K--) {
            int x, y; scanf("%d%d", &x, &y);
            int r = findroot(x);
            root[r] = i;
            e[i].push_back({r, x, (y + MOD) % MOD});
        }
    }
    for (int i = 1; i <= n; i++) if (i == findroot(i)) dfs(i);

    for (int i = 1; i <= n; i++) for (auto &arr : e[i]) {
        long long d = (query(bgn[arr[1]]) + arr[2]) % MOD;
        ans = (ans + d) % MOD;
        add(bgn[arr[0]], d);
        if (fin[arr[0]] < n) add(fin[arr[0]] + 1, -d);
    }
    printf("%lld\n", ans);
    return 0;
}

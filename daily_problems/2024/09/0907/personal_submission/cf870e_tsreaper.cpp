#include <bits/stdc++.h>
#define MAXN ((int) 1e5)
#define MOD ((int) 1e9 + 7)
using namespace std;

int n, X[MAXN + 10], Y[MAXN + 10];
long long ans;

int root[MAXN * 2 + 10], sz[MAXN * 2 + 10], cnt[MAXN * 2 + 10];
long long P[MAXN * 2 + 10];

int prepare(int *X) {
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[X[i]] = 1;
    int m = 0;
    for (auto &p : mp) p.second = ++m;
    for (int i = 1; i <= n; i++) X[i] = mp[X[i]];
    return m;
}

int findroot(int x) {
    if (root[x] != x) root[x] = findroot(root[x]);
    return root[x];
}

void merge(int x, int y) {
    x = findroot(x); y = findroot(y);
    if (x == y) return;
    sz[x] += sz[y]; cnt[x] += cnt[y];
    root[y] = x;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &X[i], &Y[i]);

    int p = prepare(X), q = prepare(Y);
    for (int i = 1; i <= p + q; i++) root[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; i++) {
        merge(X[i], Y[i] + p);
        cnt[findroot(X[i])]++;
    }

    P[0] = 1;
    for (int i = 1; i <= p + q; i++) P[i] = P[i - 1] * 2 % MOD;
    ans = 1;
    for (int i = 1; i <= p + q; i++) if (findroot(i) == i) {
        if (sz[i] > cnt[i]) ans = ans * (P[sz[i]] - 1 + MOD) % MOD;
        else ans = ans * P[sz[i]] % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}

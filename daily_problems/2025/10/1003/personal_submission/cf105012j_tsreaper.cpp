#include <bits/stdc++.h>
#define MAXN ((int) 3e5)
using namespace std;

int n, A[MAXN + 5];
long long ans;

vector<int> e[MAXN + 5];
long long f[MAXN + 5];

long long calc(int sn, long long fv) {
    return max(1LL * A[sn], fv) + sqrt(min(1LL * A[sn], fv));
}

void dfs1(int sn, int fa) {
    f[sn] = A[sn];
    for (int fn : e[sn]) if (fn != fa) {
        dfs1(fn, sn);
        f[sn] = max(f[sn], calc(sn, f[fn]));
    }
}

void dfs2(int sn, int fa, long long fv) {
    fv = calc(sn, fv);
    ans = max(ans, max(fv, f[sn]));

    multiset<long long> ms;
    for (int fn : e[sn]) if (fn != fa) ms.insert(f[fn]);
    for (int fn : e[sn]) if (fn != fa) {
        ms.erase(ms.find(f[fn]));
        long long t = fv;
        if (!ms.empty()) t = max(t, calc(sn, *prev(ms.end())));
        dfs2(fn, sn, t);
        ms.insert(f[fn]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    dfs1(1, 0); dfs2(1, 0, 0);
    printf("%lld\n", ans);
    return 0;
}

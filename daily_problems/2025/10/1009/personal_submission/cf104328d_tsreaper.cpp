#include <bits/stdc++.h>
#define MAXN ((int) 2e5)
#define MAXA ((int) 1e7)
using namespace std;

int n, ans, A[MAXN + 5];

vector<int> e[MAXN + 5];
int fac[MAXA + 5], cnt[MAXA + 5];

int dfs(int sn, int fa, int x) {
    int ret = 0;
    for (int fn : e[sn]) if (fn != fa) {
        int tmp = dfs(fn, sn, x);
        if (A[sn] % x == 0) ans = max(ans, ret + tmp + 1);
        ret = max(ret, tmp);
    }
    if (A[sn] % x == 0) {
        ans = max(ans, ret + 1);
        return ret + 1;
    } else {
        return 0;
    }
}

int main() {
    for (int i = 2; i <= MAXA; i++) if (!fac[i]) for (int j = i; j <= MAXA; j += i) fac[j] = i;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        for (int x = A[i]; x > 1; x /= fac[x]) cnt[fac[x]]++;
    }
    for (int i = 1; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        e[x].push_back(y); e[y].push_back(x);
    }

    for (int i = 2; i <= MAXA; i++) if (cnt[i] * 2 > n) {
        ans = 0;
        dfs(1, 0, i);
        if (ans * 2 > n) { printf("YES\n"); return 0; }
    }
    printf("NO\n");
    return 0;
}

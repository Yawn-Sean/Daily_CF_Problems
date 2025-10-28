#include <bits/stdc++.h>
#define MAXA 50
using namespace std;

int n, m;
bool vis[MAXA + 5];

bool flag[MAXA + 5];
vector<int> prime;

bool check(int msk) {
    for (int i = 1; i <= MAXA; i++) if (vis[i]) {
        if (i > MAXA / 2 && !flag[i]) continue;
        bool fail = true;
        for (int j = 0; j < m; j++) if (msk >> j & 1) {
            if (i % prime[j] == 0) { fail = false; break; }
        }
        if (fail) return false;
    }
    return true;
}

void solve() {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        vis[x] = true;
    }
    
    long long ans1 = 1;
    for (int i = MAXA / 2 + 1; i <= MAXA; i++) if (vis[i] && !flag[i]) ans1 *= i;

    long long ans2 = 1e18;
    for (int msk = 0; msk < (1 << m); msk++) {
        long long tmp = 1;
        for (int i = 0; i < m; i++) if (msk >> i & 1) tmp *= prime[i];
        if (check(msk)) ans2 = min(ans2, tmp);
    }
    printf("%lld\n", ans1 * ans2);
}

int main() {
    for (int i = 2; i <= MAXA; i++) if (!flag[i]) for (int j = i * 2; j <= MAXA; j += i) flag[j] = true;
    for (int i = 2; i <= MAXA / 2; i++) if (!flag[i]) prime.push_back(i);
    m = prime.size();

    int tcase; scanf("%d", &tcase);
    while (tcase--) solve();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
vector<int> g[N + 1];
int dp[N + 1];
int deg[N + 1];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d%d", &u, &v);
        if (u < v) swap(u, v);
        g[u].push_back(v);
        deg[u]++;
        deg[v]++;
    }
    long long ans = 0LL;
    for (int u = 1; u <= n; u++) {
        dp[u] = 1;
        for (auto& v : g[u]) {
            dp[u] = max(dp[v] + 1, dp[u]);
        }
        ans = max(ans, 1LL * dp[u] * deg[u]);
    }
    printf("%lld\n", ans);
    return 0;
}


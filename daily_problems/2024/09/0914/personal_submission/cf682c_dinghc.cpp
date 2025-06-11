#include <bits/stdc++.h>

using namespace std;
constexpr int N = 100'000;
int a[N];
vector<pair<int, int>> g[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int u = 1, v, w; u < n; u++) {
        scanf("%d%d", &v, &w);
        g[v - 1].emplace_back(u, w);
    }
    function<int(int, long long)> dfs = [&] (int u, long long d) -> int {
        int res = 1;
        for (auto& [v, w] : g[u]) {
            long long dv = max(d, 0LL) + w;
            if (dv <= a[v]) {
                res += dfs(v, dv);
            }
        }
        return res;
    };
    printf("%d\n", n - dfs(0, 0LL));
    return 0;
}


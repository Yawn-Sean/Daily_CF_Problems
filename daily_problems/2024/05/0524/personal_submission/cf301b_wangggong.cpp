// 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/05/0524/solution/cf301b.md
#include <iostream>
#include <cstring>

typedef long long ll;
const ll N = 100;
ll n, d, A[N + 10], xs[N + 10], ys[N + 10], dists[N + 10];
bool vis[N + 10];

ll f(ll u, ll v) {
    return (std::abs(xs[u] - xs[v]) + std::abs(ys[u] - ys[v])) * d;
}

void dijkstra(ll k) {
    memset(dists, 0x3f, sizeof dists);
    dists[k] = 0;
    for (ll i = 1; i < n; i++) {
        ll u = -1;
        for (ll v = 0; v < n; v++)
            if (!vis[v] && (u == -1 || dists[u] > dists[v]))
                u = v;
        for (ll v = 0; v < n; v++)
            if (u != v && !vis[v] && dists[v] > dists[u] + f(u, v) - A[v])
                dists[v] = dists[u] + f(u, v) - A[v];
        vis[u] = true;
    }
}

int main() {
    scanf("%lld%lld", &n, &d);
    for (ll i = 1; i + 1 < n; i++)
        scanf("%lld", A + i);
    for (ll i = 0; i < n; i++)
        scanf("%lld%lld", xs + i, ys + i);
    dijkstra(0);
    printf("%lld", dists[n - 1]);
    return 0;
}

// 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0402/solution/cf739b.md

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll N = 2e5;
ll n, A[N + 10], p, w, ans[N + 10];
vector<pll> S, G[N + 10];

void dfs(ll u, ll d) {
    S.push_back({u, d});
    ll p = 0, q = S.size();
    while (p < q) {
        ll mid = (p + q) >> 1;
        if (d - S[mid].second <= A[u])
            q = mid;
        else
            p = mid + 1;
    }
    if (p > 0)
        ans[S[p - 1].first]--;
    if (S.size() > 1)
        ans[S[S.size() - 2].first]++;
    for (auto it = G[u].begin(); it != G[u].end(); ++it)
        dfs(it->first, d + it->second);
    S.pop_back();
}

ll dfs1(ll u) {
    for (auto it = G[u].begin(); it != G[u].end(); ++it)
        ans[u] += dfs1(it->first);
    return ans[u];
}

int main() {
    scanf("%lld", &n); for (ll i = 1; i <= n; i++)
        scanf("%lld", A + i);
    for (ll i = 2; i <= n; i++)
        scanf("%lld%lld", &p, &w), G[p].push_back({i, w});
    dfs(1, 0), dfs1(1);
    for (ll i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    return 0;
}

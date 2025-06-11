#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;
const ll N = 1e5;
ll n, k, pa[N + 10], ch[N + 10], cnt[N + 10];
vector<ll> G[N + 10];
bool leaf[N + 10];

ll dfs(ll u, ll p) {
    if (leaf[u])
        return ch[u] = 1;
    for (auto v : G[u])
        ch[u] += dfs(v, u);
    return ch[u];
}

int main() {
    memset(leaf, true, sizeof leaf);
    scanf("%lld", &n); leaf[1] = n == 1;
    for (ll i = 2; i <= n; i++)
        scanf("%lld", pa + i), leaf[pa[i]] = false, G[pa[i]].push_back(i);
    dfs(1, -1);
    for (ll i = 1; i <= n; i++)
        cnt[ch[i]]++;
    for (ll i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    for (ll i = 1, j = 1; i <= n; i++) {
        for (; cnt[j] < i; j++);
        printf("%lld ", j);
    }
    return 0;
}

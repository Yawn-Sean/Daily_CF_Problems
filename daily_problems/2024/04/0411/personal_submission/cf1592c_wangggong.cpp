// 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0411/personal_submission/cf1592c_tsreaper.cpp
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll N = 1e5;
ll t, n, k, a[N + 10], u, v, _xor, f[N + 10];
bool ok;
vector<ll> G[N + 10];

ll dfs1(ll u, ll p) {
    f[u] = a[u];
    for (ll v : G[u])
        if (v != p)
            f[u] ^= dfs1(v, u);
    return f[u];
}

bool dfs2(ll u, ll p, bool zero) {
    if (!f[u])
        zero = true;
    ll cnt = 0;
    bool ans = false;
    for (ll v : G[u])
        if (v != p)
            if (dfs2(v, u, zero))
                cnt++, ans = true;
    if (f[u] == _xor) {
        if (zero)
            ok = true;
        ans = true;
    }
    if (cnt >= 2)
        ok = true;
    return ans;
}

bool check() {
    if (!_xor)
        return true;
    if (k <= 2)
        return false;
    ok = false, dfs1(1, 0), dfs2(1, 0, false);
    return ok;
}

int main() {
    scanf("%lld", &t); while (t--) {
        _xor = 0, scanf("%lld%lld", &n, &k); for (ll i = 1; i <= n; i++)
            G[i].clear(), f[i] = 0, scanf("%lld", a + i), _xor ^= a[i];
        for (ll i = 1; i < n; i++)
            scanf("%lld%lld", &u, &v), G[u].push_back(v), G[v].push_back(u);
        puts(check() ? "YES" : "NO");
    }
    return 0;
}

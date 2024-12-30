#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
// #include <unordered_map>

typedef long long ll;
const ll N = 2e5;
ll t, n, k, ans, a[N + 10], u[N + 10], tr[N + 10];

ll lowBit(ll n) {
    return n & -n;
}

ll query(ll x) {
    ll ans = 0;
    for (; x; x -= lowBit(x))
        ans += tr[x];
    return ans;
}

void add(ll x, ll v) {
    for (; x <= k; x += lowBit(x))
        tr[x] += v;
}

signed main() {
    for (scanf("%lld", &t); t--; ) {
        memset(tr, 0, sizeof tr), ans = 0;
        std::map<ll, ll> M;
        scanf("%lld", &n);
        for (ll i = 0; i < n; i++)
            scanf("%lld", a + i), M[a[i]] = 0;
        k = 0;
        for (auto &kv : M)
            kv.second = ++k;
        for (ll i = 0; i < n; i++)
            a[i] = M[a[i]];
        // for (ll i = 0; i < n; i++)
        //     u[i] = a[i];
        // std::sort(u, u + n);
        // k = std::unique(u, u + n) - u;
        // std::unordered_map<ll, ll> M;
        // for (ll i = 0; i < k; i++)
        //     M[u[i]] = i + 1;
        // for (ll i = 0; i < n; i++)
        //     a[i] = M[a[i]];
        for (ll i = 0; i < n; i++)
            ans += std::min(query(a[i] - 1), i - query(a[i])), add(a[i], 1);
        printf("%lld\n", ans);
    }
    return 0;
}

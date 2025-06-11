#include <iostream>
#include <algorithm>
#include <unordered_set>

typedef long long ll;
const ll N = 1e5;
ll t, n, q, x, a[N + 10], PS[N + 10];
std::unordered_set<ll> S;

void dfs(ll l, ll r) {
    if (a[l] == a[r - 1])
        return;
    ll m = (a[l] + a[r - 1]) / 2;
    ll p = l, q = r;
    while (p < q) {
        ll mid = (p + q) >> 1;
        if (a[mid] >= m + 1)
            q = mid;
        else
            p = mid + 1;
    }
    S.insert(PS[p] - PS[l]), S.insert(PS[r] - PS[p]);
    dfs(l, p), dfs(p, r);
}

int main() {
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld%lld", &n, &q);
        for (ll i = 0; i < n; i++)
            scanf("%lld", a + i);
        std::sort(a, a + n);
        for (ll i = 0; i < n; i++)
            PS[i + 1] = PS[i] + a[i];
        S.clear(); S.insert(PS[n]);
        dfs(0, n);
        // for (auto v : S) std::cout << v << '\t'; std::cout << std::endl;
        while (q--)
            scanf("%lld", &x), puts(S.count(x) ? "YES" : "NO");
    }
    return 0;
}

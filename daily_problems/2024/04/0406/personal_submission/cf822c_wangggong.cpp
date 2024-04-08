// 参考: https://github.com/Yawn-Sean/Daily_CF_Problems/blob/main/daily_problems/2024/04/0406/solution/cf822c.md

#include <iostream>
#include <map>

using namespace std;
typedef long long ll;
typedef map<ll, ll> mll;
const ll N = 2e5;
const ll MAXN = 1e10;
ll n, x, l, r, d, w, ans = MAXN;
mll L[N + 10], R[N + 10];

inline void relax(mll &M, ll k, ll v) {
    if (!M.count(k) || M[k] > v)
        M[k] = v;
}

int main() {
    scanf("%lld%lld", &n, &x); for (ll i = 0; i < n; i++)
        scanf("%lld%lld%lld", &l, &r, &w), d = r - l + 1, relax(L[l], d, w), relax(R[r], d, w);
    mll M;
    for (ll i = 0; i < N; i++) {
        for (auto it = R[i].begin(); it != R[i].end(); ++it)
            relax(M, it->first, it->second);
        for (auto it = L[i + 1].begin(); it != L[i + 1].end(); ++it)
            if (M.count(x - it->first))
                ans = min(ans, M[x - it->first] + it->second);
    }
    printf("%lld", ans == MAXN ? -1 : ans);
    return 0;
}

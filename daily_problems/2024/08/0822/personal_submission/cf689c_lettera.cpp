#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// const int mod = 1 ? 998244353 : 1e9 + 7;
#define int ll
void solve()
{
    // 对于一个确定的n，如何确定方案数
    // 显然n越大，方案数单调不减
    // 注意k是不确定的
    // 对a ka k*k*a k*k*k*a,枚举a不如枚举k优秀
    ll m;
    cin >> m;
    ll l = 1, r = 8 * m; // 二分n值
    auto ask = [&](ll n) {
        ll ret = 0;
        for (int k = 2;; k++)
        {
            ll x = n / (1ll * k * k * k);
            if (x < 1)
                break;
            ret += x;
        }
        return ret;
    };
    while (l < r)
    {
        ll mid = (l + r) / 2;
        ll x = ask(mid);
        if (x < m)
        {
            l = mid + 1;
        }
        else 
        {
            r = mid;
        }
       
    }
    if (ask(l) != m)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << l << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

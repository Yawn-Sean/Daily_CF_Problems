#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// const int mod = 1 ? 998244353 : 1e9 + 7;
// #define int ll

void solve()
{

    // 尝试枚举有k个bit 1的数
    int n, k;
    cin >> n >> k;
    vector<int> a(n), buck;
    vector<int> cnt(1<<14);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    if (k == 0)
    {
        for (int i=0;i<1<<14;i++)
        {
        	int c=cnt[i];
            ans +=1ll* c*(c-1)/2;
        }
    }
    else
    {
        for (int i = 0; i < 1 << 14; i++)
        {
            if (__builtin_popcount(i) == k)
            {
                buck.push_back(i);
            }
        }
        for (auto x : buck)
        {
            for (int i = 0; i < 1 << 14; i++)
            {
                ans += 1ll * cnt[i] * cnt[x ^ i];
            }
        }
        ans /= 2;
    }

    cout << ans << "\n";
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

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ans ^= x;
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] ^ i;
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = (n + 1) / i;
        if ((n + 1) / i % 2) // T=i
        {
            ans ^= pre[i - 1] ^ pre[max(0,n-cnt*i)];
        }
        else
        {
            ans ^= pre[max(0,n-cnt*i)];
        }
    }
    cout << ans;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

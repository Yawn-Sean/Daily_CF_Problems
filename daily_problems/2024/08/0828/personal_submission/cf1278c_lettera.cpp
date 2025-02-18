#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
// const int mod = 1 ? 998244353 : 1e9 + 7;
// #define int ll
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), pa(n), sb(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = (a[i] == 1) ? 1 : (-1);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] = (b[i] == 1) ? 1 : (-1);
    }
    for (int i = 0; i < n; i++)
    {
        pa[i] = (i >= 1 ? pa[i - 1] : 0) + a[i];
    }
    vector<int> id(2 * n + 1, 2 * n);
    id[n]=n;
    for (int i = n - 1; i >= 0; i--)
    {
        sb[i] = (i < n - 1 ? sb[i + 1] : 0) + b[i];
        id[sb[i] + n] = i;
    }
    int ans =n+id[n];
    for (int i = n - 1; i >= 0; i--)
    {
        int add = -(pa[i]);
        ans = min(ans, n - 1 - i + id[add + n]);
    }
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        solve();
    }
}

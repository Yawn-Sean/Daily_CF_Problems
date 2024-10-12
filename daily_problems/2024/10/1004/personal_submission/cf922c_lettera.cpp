#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
void solve()
{
    ll n, k;
    cin>>n>>k;
    for (int i = 1; i <= k; i++)
    {
        if (n % i != i - 1)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

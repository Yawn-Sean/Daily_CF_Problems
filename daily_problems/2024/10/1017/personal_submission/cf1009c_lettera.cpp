#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
    int n, m;
    cin>>n>>m;
    ll sum = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, d;
        cin >> x >> d;
        sum += x * n;
        if (d >= 0)
        {
            sum +=1ll* n * (n - 1) / 2*d;
        }
        else
        {
            int t = n / 2;
            ll tmp = t * (t + 1) / 2;
            sum+=1ll*(2*tmp-(n%2^1)*n/2)*d;
        }
    }
    cout<<fixed<<setprecision(15)<<1.0*sum/n<<"\n";
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

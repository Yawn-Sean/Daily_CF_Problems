#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

int a[N],sum[N];

int gcd(int a,int b)
{
    if(!b)return a;
    return gcd(b,a%b);
}

void solve()
{
    int n;cin >> n;
    for(int i = 1;i<=n;i++)cin >> a[i];

    sort(a+1,a+1+n);

    for(int i = 1;i<=n;i++)sum[i] = sum[i-1]+a[i];
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        ans+=(i-1)*a[i]-sum[i-1]+sum[n]-sum[i]-(n-i)*a[i];
    }
    int b = n;
    ans = ans+sum[n];
    cout << ans/gcd(ans,b) << ' ' << b/gcd(ans,b);
}

signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}

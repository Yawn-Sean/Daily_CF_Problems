#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<n;i++)
    {
    	ll l=(a[i]+x-1)/x*x;
    	ll r=l+(k-1)*x;
    	int r1=lower_bound(a.begin(),a.end(),max(a[i],r))-a.begin();
    	int r2=lower_bound(a.begin(),a.end(),r+x)-a.begin();
    	ans+=r2-r1;
    }
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
}

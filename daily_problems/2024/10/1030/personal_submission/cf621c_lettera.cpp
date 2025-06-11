#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
void solve()
{
       int n,p;
       cin>>n>>p;
       vector<double>a(n+1);
       for(int i=1;i<=n;i++)
       {
       	 int l,r;
       	 cin>>l>>r;
       	 a[i]=1.0*((r/p)-((l-1)/p))/(r-l+1);
       }
       double ans=0;
       for(int i=1;i<=n;i++)//n>=3
       {
       	 int j=i+1;
       	 if(j==n+1)
       	 {
       	 	j=1;
       	 }
       	 ans+=2000*(a[i]+a[j]-a[i]*a[j]);
       }
       cout<<fixed<<setprecision(20)<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}

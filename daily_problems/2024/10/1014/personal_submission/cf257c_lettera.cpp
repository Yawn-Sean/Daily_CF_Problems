#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
long double pi=M_PI;
//#define int ll
void solve()
{
      int n;
      cin>>n;
      vector<long double>a(n+1);
      for(int i=1;i<=n;i++)
      {
      	 int x,y;
      	 cin>>x>>y;
      	 a[i]=atan2l(y,x);
      }
      sort(a.begin()+1,a.end());
      long double ans=0;
      for(int i=1;i<n;i++)
      {
      	 ans=max(ans,a[i+1]-a[i]);
      }
      ans=min(2*pi-ans,a[n]-a[1])/pi*180;
      cout<<fixed<<setprecision(20)<<ans<<"\n";
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

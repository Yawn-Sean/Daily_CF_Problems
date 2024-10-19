#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll
bool cmp(array<double,2>a,array<double,2>b)
{
	return a[0]*a[1]*(1-b[1])>b[0]*b[1]*(1-a[1]);
}
void solve()
{
      int n;
      cin>>n;
      vector<array<double,2>>a(n+1);
      for(int i=1;i<=n;i++)
      {
      	 cin>>a[i][0]>>a[i][1];
      	 a[i][1]/=100;
      }
      sort(a.begin()+1,a.end(),cmp);
      double ans=0;
      double cur=0;
      for(int i=1;i<=n;i++)
      {
      	ans+=a[i][0]*a[i][1]+(1-a[i][1])*(a[i][0]+cur);
      	cur+=a[i][0]*a[i][1];
      }
      cout<<fixed<<setprecision(15)<<ans;
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

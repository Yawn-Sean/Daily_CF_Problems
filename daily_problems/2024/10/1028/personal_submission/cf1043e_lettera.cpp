#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
void solve()
{
       int n,m;
       cin>>n>>m;
       vector<pair<ll,ll>>a(n+1);
       vector<ll>ans(n+1);
       for(int i=1;i<=n;i++)
       {
       	cin>>a[i].first>>a[i].second;
       }
       for(int i=1;i<=m;i++)
       {
       	 int u,v;
       	 cin>>u>>v;
       	 ll res=min(a[u].first+a[v].second,a[u].second+a[v].first);
       	 ans[u]-=res;
       	 ans[v]-=res;
       }
       vector<int>ord(n+1);
       iota(ord.begin()+1,ord.end(),1);
       sort(ord.begin()+1,ord.end(),[&](int i,int j)
       {return a[i].first-a[i].second<a[j].first-a[j].second;});
       ll prex=0;
       for(int _=1;_<=n;_++)
       {
       	int i=ord[_];
       	ans[i]+=prex+(_-1)*a[i].second;
       	prex+=a[i].first;
       }
       ll sufy=0;
       for(int _=n;_>=1;_--)
       {
       	 int i=ord[_];
       	 ans[i]+=sufy+(n-_)*a[i].first;
       	 sufy+=a[i].second;
       }
       for(int i=1;i<=n;i++)
       {
       	cout<<ans[i]<<" \n"[i==n];
       }
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

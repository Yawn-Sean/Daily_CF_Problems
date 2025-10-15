#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
const int N=1e5+9;
vector<int>g[N];
int v[N];
i64 ans=0;
//树形dp
void sol()
{
   int n;cin>>n;
   for(int i=1;i<n;++i)
   {
     int u,v;cin>>u>>v;
     g[u].push_back(v);
     g[v].push_back(u);
   }
   for(int i=1;i<=n;++i)cin>>v[i];
   vector<i64>f(n+1,0),j(n+1,0);//f+,g-;
   auto dfs=[&](auto &self,int x,int fa)->void
   {
      for(auto &nx:g[x])
      {
        if(nx!=fa) self(self,nx,x);
      }//后序遍历
      for(auto &nx:g[x])
      {
        j[x]=max(j[x],j[nx]);
        f[x]=max(f[x],f[nx]);
      }
      i64 k=v[x]+f[x]-j[x];
      if(k>0)j[x]+=k;
      else f[x]-=k;
   };
   dfs(dfs,1,0);
   cout<<f[1]+j[1]<<endl;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}

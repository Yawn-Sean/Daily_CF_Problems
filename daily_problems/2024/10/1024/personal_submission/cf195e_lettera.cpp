#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
const int mod=1E9+7;
ll ans=0;
ll MOD(ll x)
{
	return (x%mod+mod)%mod;
}
struct DSU
{
    std::vector<int> f, sz,dis;
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        dis.resize(n);
        std::iota(f.begin(), f.end(), 0);
        sz.assign(n, 0);//0
    }

    int find(int x)
    {
        if(x!=f[x])
        {
        	int ret=find(f[x]);
        	dis[x]+=dis[f[x]];
        	dis[x]=MOD(dis[x]);
        	f[x]=ret;
        	return ret;
        }
        else
        {
        	return x;
        }
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y,int w)//x->y
    {
        x = find(x);
        //y = find(y);
        if (x == y)
        {
            return false;
        }
        f[x]=y;
        dis[x]+=w;
        dis[x]=MOD(dis[x]);
        ans+=w;
        ans=MOD(ans);
        return true;
    }

    int size(int x)
    {
        return sz[find(x)];
    }
};
void solve()
{
      //需要维护每个点的root以及每个点到root的距离
      int n;
      cin>>n;
      DSU dsu(n+1);
      for(int i=1;i<=n;i++)
      {
      	 int k;
      	 cin>>k;
      	 for(int j=1;j<=k;j++)
      	 {
      	 	int v,x;
      	 	cin>>v>>x;
      	 	//从root(v)到i点连边,边权为dis(v,root(v))+x
      	 	int root=dsu.find(v);
      	 	dsu.merge(root,i,x+dsu.dis[v]);
      	 }
      }
      cout<<ans<<"\n";
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

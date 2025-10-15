#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+9;
int d[N];
struct node
{
    int x,w;
    bool operator <(const node&a)const
    {
        return w==a.w?x<a.x:w>a.w;
    }
};
vector<pair<int,int>>g[N];
void dij()
{
   priority_queue<node>pq;
   pq.push({1,d[1]=0});
   bitset<N>vis;
   while(pq.size())
   {
    int x=pq.top().x;
    pq.pop();
    if(vis[x])continue;
    vis[x]=1;
    for(const auto &[y,w]:g[x])
    {
        if(d[y]>d[x]+w)
        {
            d[y]=d[x]+w;
            pq.push({y,d[y]});
        }
    }
   }
}
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    fill(d+1,d+1+n,1e18);
    for(int i=1;i<=n;++i)
    {
      cin>>a[i];
      g[i].push_back({a[i],1});
    }
    for(int i=1;i<=n;++i)
    {
      if (i < n) g[i].push_back({i+1,1});
      if (i > 1) g[i].push_back({i-1,1});
    }
    dij();
    for(int i=1;i<=n;++i)cout<<d[i]<<' ';
    cout<<endl;
    for (int i = 1; i <= n; ++i) g[i].clear();
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    while(_--)sol();
    return 0;
}


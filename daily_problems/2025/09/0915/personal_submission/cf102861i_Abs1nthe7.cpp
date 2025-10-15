#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
const int mod=1e9+7;
const int N=1e5+9;
vector<int>g[N];
//对于每一个子树，都只能有最多一个未知量（查询后）
//考虑去遍历每一颗子树跑dp,dp0为到目前，没有未知数的方案数量，dp1为有一个未知数的数量
//对于当前子树，设x为没有未知数的方案数量，y为一个未知量的数量
//dp0=x*dp0,dp1=x*dp1+y*dp0;
void sol()
{
    int n;cin>>n;
    for(int i=2;i<=n;++i)
    {
        int x;cin>>x;
        g[x].emplace_back(i);
    }
    //对于每个节点，x0是当前子树的查询u数量，x1是总数量
    auto dfs=[&](auto &self,int u)->pair<int,int>
    {
        if(g[u].size()==0)return{1,1};//叶子都是11
        int v0=0,v1=1;//v1不查询，v0查询
        for(auto &c:g[u])
        {
            auto [x0,x1]=self(self,c);
            v0=(1ll*v1*x0+1ll*v0*x1)%mod;//查询u的数量，至少一个不被查询
            v1=(1ll*v1*x1)%mod;//不查询的数量，前面总的数量*现在不查询的数量
        }
        return {v0,(v0+v1)%mod};
    };
    pair<int,int>ans=dfs(dfs,1);
    cout<<ans.second<<endl;
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

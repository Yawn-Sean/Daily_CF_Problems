#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//一个数组满足条件的情况，子数组肯定也满足条件
//可以用双指针遍历一遍
//每次移动右端点，然后可能会产生新的bad情况，然后考虑移动左端点，移动到刚好没有，ans+=r-l+1;
void sol()
{
    int n,m;cin>>n>>m;
    vector<int>p(n+1);
    for(int i=0;i<n;++i)cin>>p[i];
    vector<vector<int>>t(n+1);
    for(int i=1;i<=m;++i)
    {
        int u,v;cin>>u>>v;
        t[u].emplace_back(v);
        t[v].emplace_back(u);
    }
    vector<int>vis(n+1);
    int l=0;
    i64 ans=0;
    for(int r=0;r<n;++r)
    {
        vis[p[r]]=1;
        int cnt=0;
        for(auto &c:t[p[r]])
        {
            cnt+=vis[c];
        }
        while(cnt)
        {
            for(auto &c:t[p[l]])
            {
                if(c==p[r])cnt--;
            }
            vis[p[l]]=0;
            l++;
        }
        ans+=r-l+1;
    }
    cout<<ans<<endl;
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

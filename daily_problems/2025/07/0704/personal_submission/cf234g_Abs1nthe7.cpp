#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//构造题
//题目是有一个递推关系在的
//f(n)=max(f(x),f(n-x))+1;
//每一次对n进行折中的处理
int _max=0;
vector<vector<int>>ans(100005);
void dfs(int l,int r,int idx)
{
    if(l==r)return;
    else
    {
        dfs(l,(l+r)/2,idx+1);
        dfs((l+r)/2+1,r,idx+1);
    }
    _max=max(idx,_max);
    for(int a=l;a<=(l+r)/2;a++)
    {
        ans[idx].push_back(a);
    }
} 
void sol()
{
   int n;cin>>n;
   dfs(1,n,1);
   cout<<_max<<endl;
   for(int i=1;i<=_max;++i)
   {
     cout<<ans[i].size()<<' ';
     for(auto c:ans[i])
     {
        cout<<c<<' ';
     }
     cout<<endl;
   }
    return;
}
signed main()
{
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}

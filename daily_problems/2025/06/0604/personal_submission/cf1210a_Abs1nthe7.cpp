#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=10;
vector<int>g[N];
vector<pair<int,int>>p;
//牌刚好是对应边的
//比如1.最多就6个边，牌的1.也最多6个，但是牌有1-1这种牌型，就会导致不能完全匹配
//当n<=6的时候，1.最多就5边，可以避免相同的这种牌型，所以答案是m
//当n==7的时候，会出现重复牌型，我们最好的选择就是，只有一种重复牌型
//这样可以让我们的答案最大化，
void sol()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b;cin>>a>>b;
        p.push_back({a,b});
    }
    if(n<=6)cout<<m<<endl;
    else
    {
        int ans=0;
        for(int i=1;i<=7;++i)
          for(int j=1;j<i;++j)//遍历所有的组合-尝试节点合并
          {
            set<pair<int,int>>st;
            for(auto[x,y]:p)
            {
                if(x==i)x=j;
                if(y==i)y=j;
                //将端点映射一下-转化为6个节点
                if(x>y)swap(x,y);
                st.insert({x,y});
            }
            ans=max(ans,(int)st.size());
          }
          cout<<ans<<endl;
    }
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

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//dp[i]表示厚度为i的时候取到宽度的最大值-这样可以贪心的让上方放的书多
struct node
{
    int t,w;
};
void sol()
{
    int n;cin>>n;
    vector<node>g;
    int tsum=0,wsum=0;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        g.push_back({x,y});
        tsum+=x;
        wsum+=y;
    }
    vector<int>dp(210,-1e9);
    dp[0]=0;
    for(auto&[x,y]:g)
    {
        for(int i=tsum;i>=x;--i)
        {
            dp[i]=max(dp[i],dp[i-x]+y);
        }
    }
    for(int i=1;i<=tsum;++i)//遍历厚度
    {
        if(wsum-dp[i]<=i)//所需的宽度小于现在的长度
        {
            cout<<i<<endl;
            return;
        }
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

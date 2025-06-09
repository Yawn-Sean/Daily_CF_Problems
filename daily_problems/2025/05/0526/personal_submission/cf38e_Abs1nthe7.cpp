#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
//dp题
//1.坐标记得sort
//2.n点必须固定
//3.前缀和来计算滚动的成本
//4.考虑dp[i]-位置为i的最小成本-like dij的贪心，前面的固定点实现min
void sol()
{
    int n;cin>>n;
    vector<int>x(n+1),c(n+1);
    for(int i=0;i<n;++i)cin>>x[i]>>c[i];
    vector<int>order(n);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&](int i,int j){return x[i]>x[j];});//根据x坐标排序
    vector<int>pre(n+1,0);
    for(int i=0;i<n;++i)//前缀和计算每个小球的位置改变
    {
        pre[i+1]=pre[i]+x[order[i]];
        //cout<<pre[i+1]<<" \n"[i==n-1];
    }
    vector<int>dp(n+2,1e18);//i为固定点的——min
    dp[0]=0;
    for(int i=0;i<n;++i)//从右到左进行dp
      for(int j=0;j<=i;++j)
      {
        dp[i+1]=min(dp[i+1],dp[j]+c[order[i]]+pre[i+1]-pre[j]-1ll*x[order[i]]*(i+1-j));//dp[j]->dp[i]要加上中间小球的贡献
      }
    cout<<dp[n]<<endl;
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

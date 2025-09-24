#pragma GCC optimize(3, "Ofast", "inline", "unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
const int mod=1e9+7;
//组合数学或者是dp吧，先搞懂样例
//不对，in a row是连续。。，那应该是dp
//设计状态的话，dp[i][j]-i是几个积木，j是当前什么颜色
//状态转移的话，我们每一次将前面的所有颜色加一起，然后加上现在的颜色，同时进行判断，是否超过限制，超过的话就剪掉那部分
inline void add(i64 &x,i64 y)
{
    x+=y;
    if(x>=mod)x-=mod;
}
inline void del(i64 &x,i64 y)
{
    x-=y;
    if(x<0)x+=mod;
}
void sol()
{
    int n,r,g,b;cin>>n>>r>>g>>b;
    vector<vector<i64>>dp(n+1,vector<i64>(4,0));
    dp[1][1]=1,dp[1][2]=1,dp[1][3]=1;
    for(int i=2;i<=n;++i)
    {
        i64 now=dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
        for(int j=1;j<=3;++j)
        {
            if(j==1)
            {
                dp[i][1]=now;
                if(i>r+1)
                {
                    del(dp[i][1],dp[i-r-1][2]);
                    del(dp[i][1],dp[i-r-1][3]);
                }
                if(i==r+1)del(dp[i][1],1);
            }
            else if(j==2)
            {
                dp[i][2]=now;
                if(i>g+1)
                {
                    del(dp[i][2],dp[i-g-1][1]);
                    del(dp[i][2],dp[i-g-1][3]);
                }
                if(i==g+1)del(dp[i][2],1);
            }
            else
            {
                dp[i][3]=now;
                if(i>b+1)
                {
                    del(dp[i][3],dp[i-b-1][1]);
                    del(dp[i][3],dp[i-b-1][2]);
                }
                if(i==b+1)del(dp[i][3],1);
            }
            dp[i][j]%=mod;
            if(dp[i][j]<0)dp[i][j]+=mod;
        }
    }
    i64 ans=0;
    add(ans,dp[n][1]);
    add(ans,dp[n][2]);
    add(ans,dp[n][3]);
    cout<<ans%mod<<endl;
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

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void sol()
{
    int n,k,x;
    cin>>n>>k>>x;
    vector<int>dp(1024,0),ndp(1024,0);
    //dp记录i出现的次数
    //ndp记录下一轮的数值分布
    for(int i=1;i<=n;++i)
    {
        int x;cin>>x;
        dp[x]++;
    }
    while(k--)
    {
       int cur=0;
       for(int i=0;i<1024;++i)//最大值是1000^1000,两个9位二进制的异或，最大值不会到10位二进制
       {
         int a=dp[i]-dp[i]/2;//奇数的分配量
         int b=dp[i]/2;//偶数的分配量
         //当dp[i]为奇数的时候 a会比b大1
         if(cur)//当前处理奇数位
         {
            ndp[i^x]+=b;//后面一半元素异或
            ndp[i]+=a;//前一半保持
         }
         else//偶数位
         {
            ndp[i^x]+=a;
            ndp[i]+=b;
         }
         cur^=dp[i]&1;//更新位置奇偶性
       }
        for(int i=0;i<1024;++i)
         {
           dp[i]=ndp[i];//递推传递
           ndp[i]=0;
         }
    }
    int l=-1,r=-1;
    for(int i=0;i<1024;++i)
    {
        if(dp[i])
        {
            l=(l==-1?i:l);
            r=i;
        }
    }
    cout<<r<<' '<<l<<endl;
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

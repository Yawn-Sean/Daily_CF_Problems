#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//题目大意：we have some chains and a dot.we try to create a new chains ans find the dots location(initial chains can't change)
//转化为一个类似背包问题，每一个chain占一定的长度，看看当前的dot能不能往现有位置后面放；
void sol()
{
   int n,x;cin>>n>>x;
   vector<int>pre(n+1);
   for(int i=1;i<=n;++i)cin>>pre[i];
   vector<int>note(n+1,1);
   //如果pre[x]!=0的话，x就不会是链尾
   //0不记录
   for(int i=1;i<=n;++i)
   {
    note[pre[i]]=0;
   }
   //dp[i]表示前i位置里，有合法放置其他链的可能
   vector<bool>dp(n+1,0);
   dp[0]=1;

   int pos;//链里相对位置
   for(int i=1;i<=n;++i)
   {
     if(note[i])//链尾
     {
       int cur=i,cnt=0;
       bool ok=false;
       while(cur)
       {
         cnt++;
         if(cur==x)
         {
            pos=cnt;
            ok=true;//dot在现在的链里
         }
         cur=pre[cur];//往前走
       }
       if(ok)pos=cnt+1-pos;//转化为链的正向位置 4+1-3=2;
       else//不在链里
       {
         for(int j=n;j>=cnt;--j)
         {
            if(dp[j-cnt])//如果前面有排法占了j-cnt的位置，那现在dot可以放到j位置；
            {
                dp[j]=1;
            }
         }
       }
     }
   }
   //pos的最差情况是1，
   for(int i=0;i<=n;++i)
   {
    if(dp[i])cout<<i+pos<<endl;
   }
    return;
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

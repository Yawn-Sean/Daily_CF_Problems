#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int dp[110][30][100];//前i个字符，现在的字符为j,已经改变k；
//dp[i][j][cnt]=dp[i-1][ch][cnt]+c[ch][j]//使用原来的字符
//dp[i][j][cnt]=dp[i-1][ch][cnt-1]+c[ch][j]//使用改变的字符
int c[30][30];
void sol()
{
    int n,k;string s;
    cin>>s>>k>>n;
    int m=s.size();
    s=' '+s;
    for(int i=1;i<=n;++i)
    {
        char x,y;
        int w;
        cin>>x>>y>>w;
        c[x-'a'][y-'a']=w;
    }
    //初始化
    for(int i=1;i<=m;++i)
      for(int j=0;j<26;++j)
        for(int cnt=0;cnt<=k;++cnt)
        {
            dp[i][j][cnt]=-1e18;
        }
    dp[1][s[1]-'a'][0]=0;
    //开头初始化
    for(int j=0;j<26;++j)
    {
        if(j!=s[1]-'a')
        {
            dp[1][j][1]=0;
        }
    }
    for(int i=2;i<=m;++i)
      for(int j=0;j<26;++j)
        for(int cnt=0;cnt<=min(i,k);++cnt)
        {
            for(int ch=0;ch<26;++ch)
            {
                if(j==s[i]-'a')
                {
                    dp[i][j][cnt]=max(dp[i][j][cnt],dp[i-1][ch][cnt]+c[ch][j]);//直接加上贡献
                }
                else
                {
                    if(cnt>0)dp[i][j][cnt]=max(dp[i][j][cnt],dp[i-1][ch][cnt-1]+c[ch][j]);
                }
            }
        }
    int ans=-1e18;
    for(int j=0;j<26;++j)
      for(int cnt=0;cnt<=k;++cnt)
      {
        ans=max(ans,dp[m][j][cnt]);
      }
      cout<<ans<<endl;
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

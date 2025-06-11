#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod=1e9+7;
vector<vector<int>>mul(vector<vector<int>>&a,vector<vector<int>>&b)
{
   int n=a.size();
   vector<vector<int>>res(n,vector<int>(n,0));
   for(int i=0;i<n;++i)
     for(int k=0;k<n;++k)
       for(int j=0;j<n;++j)
       {
        res[i][j]=(res[i][j]+a[i][k]*b[k][j]%mod)%mod;
       }
       return res;
}
vector<vector<int>>gpow(vector<vector<int>>&base,int b)
{
  int n=base.size();
  vector<vector<int>>res(n,vector<int>(n,0));
  for(int i=0;i<n;++i)res[i][i]=1;
  while(b)
  {
    if(b&1)res=mul(res,base);
    base=mul(base,base),b>>=1;
  }
  return res;
}
void sol()
{
    int m,n;
    cin>>m>>n;
    vector<int>s(m+1),l(m+1);
    for(int i=0;i<m;++i)cin>>s[i];
    for(int i=0;i<m;++i)cin>>l[i];
    for(int i=0;i<m;++i)s[i]+=l[i];
    vector<vector<int>>g(m,vector<int>(m));
    for(int i=0;i<m;++i)
      for(int j=0;j<m;++j)
      {
        g[i][j]=s[i]*s[j]-l[i]*l[j];//i-j的方案数
        g[i][j]%=mod;
      }

    auto res=gpow(g,n);
    int ans=0;
    for(int i=0;i<m;++i)
    {
        ans+=res[0][i];//从1开始的方案数
        ans%=mod;
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

#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
const int mod=1e6+3;
const int N=5e6+9;
i64 fac[N+5],inv[N+5];
//组合数学
//相当于把n个球放入c个盒子
void init()
{
    fac[1]=fac[0]=1;
    for(int i=1;i<N;++i)
    {
        fac[i]=i*fac[i-1]%mod;
    }
    inv[1]=1,inv[0]=1;
    for(int i=2;i<N;++i)
    inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    for(int i = 2; i < N; ++i)
    inv[i] = inv[i] * inv[i - 1] % mod;
}
i64 qmi(i64 a,i64 b)
{  
   i64 res=1;
   while(b)
   {
      if(b&1)res=res*a%mod;
      a=a*a%mod,b>>=1;
   } 
   return res%mod;
}
i64 C(int n,int m)
{
    if(n<0||m<0||n<m)return 0;
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}
void sol()
{
    i64 n,c;cin>>n>>c;
    i64 ans=0;
    for(int i=1;i<=n;++i)
    {
        //debug(C(c-1+i,i));
        ans=(ans+C(c-1+i,i))%mod;
    }
    cout<<ans<<endl;
    return;
}
signed main()
{
    init();
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}

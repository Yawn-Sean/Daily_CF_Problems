#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=998244353;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;

int n,m,k;
int a[N],b[N];
int f[1010][2010][1<<2];
void solve()
{
    cin>>n>>k;
    //0 black 1 write
    f[1][1][0]=1;
    f[1][1][3]=1;
    f[1][2][1]=1;
    f[1][2][2]=1;
    
    auto get=[&](int x,int y)->long long{

        int res=0;
        if((x>>0&1)!=(y>>0&1)) res++;
        if((x>>1&1)!=(y>>1&1)) res++;
        if((y>>0&1)==(y>>1&1)) res--;
        return max(0ll,res);
    };
    
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int p=0;p<1<<2;p++)
            {
                for(int q=0;q<1<<2;q++){
                    int need=get(q,p);
                    if(j-need>=0)
                    f[i][j][p]+=f[i-1][j-need][q];
                    f[i][j][p]%=mod;
                }
            }
            //00 00
            // f[i][j][0]=f[i-1][j][0];
            // //00 01
            // f[i][j][0]+=f[i-1][j][1];
            // //00 10
            // f[i][j][0]+=f[i-1][j][2];
            // //00 11
            // f[i][j][0]+=f[i-1][j-1][3];
            
            // //01 00
            // f[i][j][1]=f[i-1][j-1][0];
            // //01 01
            // f[i][j][1]=f[i-1][j][1];
            
        }
    }
    int res=0;
    for(int i=0;i<1<<2;i++) res=(res+f[n][k][i])%mod;
    cout<<res;
}   
signed main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
 
  //  cin>>t;
    while(t--) solve();
}

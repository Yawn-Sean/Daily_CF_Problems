#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2*N,mod=1e8+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<uLL,int,int>;
int n,m,k,p;
int f[N];

int s[N];
void solve()
{
    //memset(f,-1,sizeof(f));
    cin>>n>>p;
    f[1]=1;
    s[1]=1;
    for(int i=2;i<=n;i++)
    {
        
        for(int l=2,r;l<=i;l=r+1){
            r=min(i,i/(i/l));
            f[i]+=(r-l+1)*f[i/l]%p;
            f[i]%=p;
        }
        f[i]+=s[i-1];
        f[i]%=p;
        s[i]=(s[i-1]+f[i])%p;
    }
    cout<<f[n]<<"\n";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;

   // cin>>t;
    while(t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef double dl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// #define int long long
#define endl '\n'
const int MOD=998244353;
const double PI = 3.14159265358979323846;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
LL qmi(LL m,LL k,int p)
{
    LL ans=1LL%p;
    while(k)
    {
        if(k&1)ans=ans*m%p;
        m=m*m%p;
        k>>=1;
    }
    return ans;
}
LL inv(LL x)
{
    return qmi(x,MOD-2,MOD);
}
const int N=1e6+10;
LL fac[N];
LL s[N];
LL C(LL x,LL y)
{
    return fac[x]*inv(fac[y])%MOD*inv(fac[x-y])%MOD;
}
void solve()
{
    int n;
    cin>>n;
    cout<<s[n]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fac[0]=1;
    for(int i=1;i<N;i++)
    {
        fac[i]=fac[i-1]*i%MOD;
        // if(i<20)cout<<fac[i]<<endl;
    }
    for(int i=1;i<N;i++)
    {
        s[i]=s[i-1]^1;
        if(i%2==0)s[i]^=C(i,i/2);
    }
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

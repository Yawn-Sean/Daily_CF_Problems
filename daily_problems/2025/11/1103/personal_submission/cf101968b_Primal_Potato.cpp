#include <bits/stdc++.h>
using namespace std;
typedef double dl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
// #define int long long
#define endl '\n'
const int MOD=1e9+7,mod=998244353;
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
void solve()
{
    int n;
    cin>>n;
    vector<PII> p(2*n+1);
    vector<LL> x(2*n+1),y(n*2+1);
    for(int i=1;i<=n*2;i++)
    {
        cin>>x[i]>>y[i];
        x[i]*=2,y[i]*=2;
        p[i]={x[i],y[i]};
    }
    sort(x.begin()+1,x.end());
    sort(y.begin()+1,y.end());
    int xmid=(x[n]+x[n+1])/2;
    int ymid=(y[n]+y[n+1])/2;
    int cx=0,cy=0;
    for(int i=1;i<=n*2;i++)
    {
        LL x=p[i].first,y=p[i].second;
        if(x==xmid)cx++;
        if(y==ymid)cy++;
    }
    // cout<<xmid<<' '<<ymid<<endl;
    if(cx>1 || cy>1)
    {
        cout<<0<<endl;
        return;
    }
    LL a1=0,a2=0;
    for(int i=1;i<=2*n;i++)
    {
        LL x=p[i].first,y=p[i].second;
        if(x<xmid && y<ymid)a1++;
        if(x>xmid && y<ymid)a2++;
    }
    // cout<<a1<<' '<<a2<<endl;
    LL ans=1;
    for(int i=1;i<=a1;i++)
    {
        ans=(ans*i)%MOD;
    }
    for(int i=1;i<=a2;i++)
    {
        ans=(ans*i)%MOD;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

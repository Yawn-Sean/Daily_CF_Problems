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
    string a,b,op;
    cin>>a>>op>>b;
    LL aa=0,bb1=0,bb2=0;
    LL cnt1=1,cnt2=1;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(auto x:a)
    {
        int t=(int)(x-'0');
        aa=(aa+cnt1*t%MOD)%MOD;
        cnt1=cnt1*10%MOD;
    }
    cnt1=1,cnt2=1;
    for(auto x:b)
    {
        int t=(int)(x-'0');
        bb1=(bb1+cnt1*t%MOD)%MOD;
        bb2=(bb2+cnt2*t%(MOD-1))%(MOD-1);
        cnt1=cnt1*10%MOD;
        cnt2=cnt2*10%(MOD-1);
    }
    if(op!="^")
    {
        if(op=="+")cout<<(aa+bb1)%MOD<<endl;
        else if(op=="-")cout<<((aa-bb1)%MOD+MOD)%MOD<<endl;
        else if(op=="*")cout<<(aa*bb1)%MOD<<endl;
    }
    else
    {
        cout<<qmi(aa,bb2,MOD)<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

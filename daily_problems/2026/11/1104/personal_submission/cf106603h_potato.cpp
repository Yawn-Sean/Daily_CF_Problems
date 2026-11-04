#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
using ll=long long;
using PII=pair<int,int>;
using ld=long double;
using u32=unsigned int;
using u64=unsigned long long;
using i128=__int128_t;
using u128=__uint128_t;
mt19937_64 rnd(
    static_cast<u64>(
        chrono::steady_clock::now().time_since_epoch().count()
    )
);
const int mod=998244353;
const ll inf=0x3f3f3f3f3f3f3f3f;//0x3f3f3f3f;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const ld PI = acos(-1);
const ld eps = 1e-12L;
const ld INF = numeric_limits<ld>::max();
ll ksm(ll m,ll k,int p)
{
    m%=p;
    ll ans=1LL%p;
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
    if(n==2 || n==3)
    {
        cout<<1<<endl;
        return;
    }

    n-=2;
    if(n%3==0)
    {
        cout<<ksm(3,n/3,mod)<<endl;
    }
    else if(n%3==1)
    {
        cout<<ksm(3,n/3-1,mod)*4%mod<<endl;
    }
    else 
    {
        cout<<ksm(3,n/3,mod)*2%mod<<endl;
    }
}
signed main()
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

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
const int mod=1e9+7;//998244353;
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
    string s;
    cin>>s;
    string s1,s2;
    for(int i=1;i<=n;i++)
    {
        if(i&1)s1+='G',s2+='V';
        else s1+='V',s2+='G';
    }
    if(s==s1 || s==s2)
    {
        cout<<n<<endl;
        return;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='G')ans++;
        else ans+=2;
    }
    ans%=3;
    if(ans==0)cout<<2<<endl;
    else cout<<1<<endl;
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

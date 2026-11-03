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
const int N=1e6+10;
const u64 mod1 = 4294967291ULL; // 2^32 - 5
const u64 mod2 = 4294967279ULL; // 2^32 - 17
const u64 base1 = uniform_int_distribution<u64>(256, mod1 - 2)(rnd);
const u64 base2 = uniform_int_distribution<u64>(256, mod2 - 2)(rnd);
u64 f1[N],val1[N];
u64 f2[N],val2[N];
void solve()
{
    int q,n;
    cin>>q>>n;
    vector<u64> a(n+10),s(q+10);
    iota(a.begin(),a.end(),0);
    val1[0]=val2[0]=1;
    for(int i=1;i<=n;i++)
    {
        val1[i]=val1[i-1]*base1%mod1;
        val2[i]=val2[i-1]*base2%mod2;
    }
    u64 res1=0,res2=0;
    for(int i=1;i<=n;i++)
    {
        f1[i]=val1[i]*a[i]%mod1;
        res1=(res1+f1[i])%mod1;
        f2[i]=val2[i]*a[i]%mod2;
        res2=(res2+f2[i])%mod2;
    }

    s[0]=(res1<<32)|res2;

    for(int i=1;i<=q;i++)
    {
        int l,r;
        cin>>l>>r;
        res1+=(a[r]+mod1-a[l])%mod1*((val1[l]+mod1-val1[r])%mod1)%mod1;
        res1%=mod1;
        res2+=(a[r]+mod2-a[l])%mod2*((val2[l]+mod2-val2[r])%mod2)%mod2;
        res2%=mod2;
        swap(a[l],a[r]);
        s[i]=(res1<<32)|res2;
    }
    map<u64,int> mp;
    for(int i=0;i<=q;i++)mp[s[i]]++;
    int ans=0;
    for(auto [x,y]:mp)ans+=(y-1)*y/2;
    cout<<ans<<endl;
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

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
// //质数筛
vector<int> prime, minp;
void sieve(int n = 1e6) {
    minp.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) 
        {
            minp[i] = i;
            prime.push_back(i);
        }
        for (auto j : prime) 
        {
            if (j > minp[i] || j > n / i) break;
            minp[i * j] = j;
        }
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<PII> a(n+1);
    int maxzz=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        maxzz=max(maxzz,y);
        a[i]={x,y};
    }
    maxzz++;
    
    sort(a.begin()+1,a.end());
    int g=0;
    for(int i=1;i<n;i++)
    {
        g=gcd(g,abs(k*(a[i+1].first-a[i].first)-(a[i+1].second-a[i].second)));
    }
    if(g==0)
    {
        cout<<maxzz<<endl;
        return;
    }
    // cout<<g<<endl;
    int ans=inf;

    for(int i=1;i*i<=g;i++)
    {
        if(i*i>g)break;
        if(g%i==0)
        {
            if(i>=maxzz)ans=min(ans,i);
            if(g/i>=maxzz)ans=min(ans,g/i);
        }
    }
    if(ans<inf)cout<<ans<<endl;
    else cout<<-1<<endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    sieve();
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

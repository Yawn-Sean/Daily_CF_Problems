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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> dis(n+10,inf);
    vector<bitset<8010>> bs(n+10);
    vector<vector<int>> g(n+10,vector<int>());
    vector<int> a;
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> q;
    q.push_back(1);
    dis[1]=0;
    for(int idx=0;idx<q.size();idx++)
    {
        int u=q[idx];
        for(auto& i:g[u])
        {
            if(dis[u]+1<dis[i])
            {
                dis[i]=dis[u]+1;
                q.push_back(i);
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        bs[a[i]][i+1]=1;
    }

    reverse(q.begin(),q.end());
    for(auto& u:q)
    {
        for(auto& v:g[u])
        {
            if(dis[u]+1==dis[v])
            {
                bs[u]|=bs[v];
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(bs[i].count()==k)
        {
            ans=max(ans,dis[i]);
        }
    }
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

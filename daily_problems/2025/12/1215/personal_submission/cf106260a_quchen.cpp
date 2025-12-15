#include <bits/stdc++.h>
using namespace std;
const int N=3e5+10;
const int mod = 998244353;

typedef long long ll;
int n;

vector<int>e[N];
int deep[N];

ll qpow(ll a,ll b,ll p)
{
    ll res = 1;
    for(;b;b>>=1)
    {
        if(b&1)
        {
            res = res*a%p;
        }
        a = a*a%p;
    }
    return res;
}

void dfs(int u,int fa)
{
    deep[u]=deep[fa]+1;
    for(auto v:e[u])
    {
        if(v==fa)continue;
        dfs(v,u);
    }

}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        deep[i]=0;
        e[i].clear();
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(1,0);
    ll ans = 0;
    ll invn = qpow(n,mod-2,mod);
    for(int i=1;i<=n;i++)
    {
        ans = (ans+qpow(deep[i],mod-2,mod)%mod)%mod;
    }   
    cout<<ans<<'\n';


}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }


    return 0;
}

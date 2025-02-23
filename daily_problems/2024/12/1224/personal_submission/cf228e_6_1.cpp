#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;
int st[N];

void solve()
{
    int n,m;cin >> n >> m;
    memset(st,-1,sizeof st);
    vector<vector<pii>> adj(n+1);
    for(int i = 1;i<=m;i++)
    {
        int a,b,c;cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    auto dfs = [&](auto &&dfs,int u) -> bool
    {
        int flag = 1;
        for(auto [v,c]:adj[u])
        {
            int now = (c?st[u]:st[u]^1);
            if(st[v]<0)
            {
                st[v] = now;
                flag &= dfs(dfs,v);
            }
            else 
            {
                if(st[v]!=now)return false;
            }
            if(!flag)return false;
        }
        return flag;
    };
    int flag = 1,cnt = 0;
    for(int i = 1;i<=n;i++)
    {
        if(st[i]<0)st[i] = 0,flag = dfs(dfs,i);
        if(!flag){cout << "Impossible\n";return;}
        cnt+=st[i];
    }
    cout << cnt << endl;
    for(int i = 1;i<=n;i++)
    {
        if(st[i])cout << i << ' ';
    }
    cout << endl;
}

signed main()
{
    IOS
    int tt = 1;
    // cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}

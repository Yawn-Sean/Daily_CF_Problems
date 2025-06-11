#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> pii;

const int N = 2e5+10;
vector<vector<int>> adj;

int w[N],sz[N],id[N],cnt,son[N],top[N],fa[N],dep[N];
pii e[N];

void dfs(int u,int fat)
{
    sz[u] = 1,fa[u] = fat,dep[u] = dep[fat]+1;
    for(auto v:adj[u])
    {
        if(v==fat)continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]])son[u] = v;
    }
}

void dfs1(int u)
{
    if(u==son[fa[u]])top[u] = top[fa[u]];
    else top[u] = u;
    cnt++;
    id[u] = cnt;
    if(!son[u])return;
    dfs1(son[u]);
    for(auto v:adj[u])
    {
        if(v!=fa[u]&&v!=son[u])dfs1(v);
    }
}

int find(int q)
{
    int x = e[q].first,y = e[q].second;
    return (dep[x]>dep[y]?x:y);
}

void add(int i,int x)
{
    while(i<N)
    {
        w[i]+=x;
        i+=(i&-i);
    }
}

int ask(int i)
{
    int res = 0;
    while(i)
    {
        res+=w[i];
        i-=(i&-i);
    }
    return res;
}

int ask(int l,int r)
{
    return ask(r)-ask(l-1);
}

void modify(int u,int x)
{
    int xx = e[u].first,yy = e[u].second;
    if(dep[xx]<dep[yy])swap(xx,yy);
    add(id[xx],x);
}

pii query(int a,int b)
{
    int res = 0;
    while(top[a]!=top[b])
    {
        if(dep[top[a]]<dep[top[b]])swap(a,b);
        res += ask(id[top[a]],id[a]);
        a = fa[top[a]];     
    }
    if(dep[a]<dep[b])swap(a,b);
    res+=ask(id[b]+1,id[a]);
    return {res,b};
}

void solve()
{
    int n;cin >> n;
    adj.resize(n+1);
    for(int i = 1;i<=n-1;i++)
    {
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        e[i] = {a,b};
    }
    dfs(1,0);
    dfs1(1);
    int m;cin >> m;
    while(m--)
    {
        int a;cin >> a;
        if(a==1)
        {
            int b;cin >> b;
            modify(b,-1);
        }
        if(a==2)
        {
            int b;cin >> b;
            modify(b,1);
        }
        if(a==3)
        {
            int b,c;cin >> b >> c;
            pii t = query(b,c);
            if(!t.first)
            {
                int lca = t.second;
                cout << dep[b]-dep[lca]+dep[c]-dep[lca] << endl;
            }
            else cout << -1 << endl;
            // cout << t.first << endl;

        }
    }
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

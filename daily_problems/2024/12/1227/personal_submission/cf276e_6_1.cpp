#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 2e5+10;

vector<vector<int>> adj;

int id[N],w[N],sz[N],tot,dep[N],fenwick[N],fenwick1[N],top[N],root;

void add(int i,int x)
{
    while(i<N)
    {
        fenwick[i]+=x;
        i+=i&-i;
    }
}

int ask(int i)
{
    int res = 0;
    while(i)
    {
        res += fenwick[i];
        i -= i&-i;
    }
    return res;
}

void add1(int i,int x)
{
    while(i<N)
    {
        fenwick1[i]+=x;
        i+=i&-i;
    }
}

int ask1(int i)
{
    int res = 0;
    while(i)
    {
        res += fenwick1[i];
        i -= i&-i;
    }
    return res;
}

void dfs(int u,int fa)
{
    sz[u] = 1,id[u] = ++tot,dep[u] = dep[fa]+1;
    if(fa==root)top[u] = u;
    else top[u] = top[fa];
    for(auto v:adj[u])
    {
        if(v!=fa)
        {
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
}

void debug()
{
    for(int a = 1;a<=3;a++)
    cout << ask(dep[a])+ask1(id[a]) << endl;
}

void solve()
{
    int n,m;cin >> n >> m;
    adj.clear();
    adj.resize(n+1);
    int mx = 0;
    for(int i = 1;i<=n-1;i++)
    {
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1;i<=n;i++)
    {
        int nn = adj[i].size();
        if(mx<nn)mx = nn,root = i;
    }
    dfs(root,0);

    while(m--)
    {
        int t,a,b,c;cin >> t;
        if(t==0)
        {
            cin >> a >> b >> c;
            if(a==root)
            {
                add(1,b);
                add(2+c,-b);
                // debug();
                continue;
            }
            int d = c-(dep[a]-dep[top[a]]);//走到top之后还走
            add1(max(id[a]-c,id[top[a]]),b);
            add1(min(id[a]+c,id[a]+sz[a]-1)+1,-b);
            if(d>0)
            {
                add(1,b);
                add(d+1,-b);
                if(d>=2)
                {
                    add1(id[top[a]],-b);
                    add1(id[top[a]]+min((d-dep[top[a]]),sz[top[a]]-1)+1,b);
                }
            }
            // debug();
        }
        else 
        {
            cin >> a;
            cout << ask(dep[a])+ask1(id[a]) << endl;
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

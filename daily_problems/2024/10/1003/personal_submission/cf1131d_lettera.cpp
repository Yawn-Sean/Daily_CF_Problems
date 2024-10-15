#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// #define int ll
struct DSU
{
    std::vector<int> f, siz;
    DSU()
    {
    }
    DSU(int n)
    {
        init(n);
    }

    void init(int n)
    {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }

    int find(int x)
    {
        while (x != f[x])
        {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
        {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }

    int size(int x)
    {
        return siz[find(x)];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n + m);
    vector<vector<int>> g(n + m);
    vector<string> a(n);
    vector<int> in(n + m);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a[i] = s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '=')
            {
                int u = dsu.find(i), v = dsu.find(n + j);
                dsu.merge(u, v);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        string s = a[i];
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '<')
            {
                int u = dsu.find(i), v = dsu.find(n + j);
                g[u].push_back(v);
                in[v]++;
            }
            else if (s[j] == '>')
            {
                int v = dsu.find(i), u = dsu.find(n + j);
                g[u].push_back(v);
                in[v]++;
            }
        }
    }
    vector<int> ans(n + m, 1),vis(n+m);
    queue<int> q;
    for (int i = 0; i < n + m; i++)
    {
    	int x=dsu.find(i);
        if (!in[x]&&!vis[x])
        {
            q.push(x);
            vis[x]=1;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cnt+=dsu.size(u);
        for (auto v : g[u])
        {
            in[v]--;
            ans[v]=max(ans[v],ans[u]+1);
            if(!in[v])
            {
            	q.push(v);
            }
        }
    }
    if (cnt == n + m)
    {
        cout << "Yes\n";
        for(int i=0;i<n+m;i++)
        {
        	cout<<ans[dsu.find(i)]<<" \n"[i==n-1||i==n+m-1];
        }
    }
    else
    {
        cout << "No\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}

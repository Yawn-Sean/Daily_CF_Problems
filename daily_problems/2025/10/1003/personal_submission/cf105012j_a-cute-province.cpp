    #include <bits/stdc++.h>
    #define x first
    #define y second
    #define int long long
    #define cute_prov0nce main
    using namespace std;
    #define all(x) x.begin(),x.end()
    typedef pair<int, int> PII;
    using i64 = long long;
    const int N = 2e5+10;
    const int mod = 1e9 + 7;

    void solve()
    {
        int n;
        cin >> n;
        vector<int> a(n), dp1(n), dp2(n);
        for(int i = 0; i < n; i++)cin >> a[i];
        vector<vector<int>> g(n);
        for(int i = 1; i < n; i ++){
            int u, v;
            cin >> u >> v;
            v--;
            u--;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        int ans = 0;
        auto f = [&](int x, int y)->int{
            return max(x, y) + (int)sqrt(min(x, y));
        };
        auto dfs1 = [&](auto &dfs1, int u, int fa)->void{
            dp1[u] = a[u];
            for(auto v : g[u]){
                if (v != fa) {
                    dfs1(dfs1, v, u);
                    dp1[u] = max(dp1[u], f(a[u], dp1[v]));
                }
            }
            return;
        };
        
        auto dfs2 = [&](auto &dfs2, int u, int fa)->void{
            dp2[u] = max(dp2[u], a[u]);
            int v1 = dp2[u], v2 = 0;
            for(auto v : g[u]){
                if (v != fa) {
                    int nv = f(a[u], dp1[v]);
                    if(nv > v1)v2 = v1, v1 = nv;
                    else if(nv > v2)v2 = nv;
                }
            }
            for(auto v : g[u]){
                if(v != fa){
                    int nv = f(a[u], dp1[v]);
                    if(nv == v1)dp2[v] = f(v2, a[v]);
                    else dp2[v] = f(v1, a[v]);
                    dfs2(dfs2, v, u);
                }
            }
            return;
        };
        dfs1(dfs1, 0, -1);
        dfs2(dfs2, 0, -1);
        cout << max(*max_element(dp1.begin(), dp1.end()), *max_element(dp2.begin(), dp2.end()))<< '\n';


    }
    signed cute_prov0nce()
    {
    #ifdef ACM_LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int t;
        //cin >> t;
        t = 1;
        while (t--)
        {
            solve();
        }
        return 0;
    }

    #include <bits/stdc++.h>
    #define x first
    #define y second
    #define int long long
    #define cute_prov0nce main
    using namespace std;
    #define all(x) x.begin(),x.end()
    typedef pair<int, int> PII;
    using i64 = long long;
    const int N = 1e6 + 10; 


    void solve()
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1),id(n+1);
        for(int i = 1; i <= m; i++){
            int x, y;
            cin >> x >> y;
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        int w;
        cin >> w;
        vector<int> c(w+1), k(w+1), p(w+1);
        vector<array<int, 3>> shop;
        for(int i =1; i <= w; i++){
            cin >> c[i] >> k[i] >> p[i];
            shop.push_back({p[i], k[i],c[i] });
        } 
        sort(shop.begin(), shop.end());
        int q;
        cin >> q;
        vector<int> g(q+1), r(q+1), a(q+1);
        for(int i = 1; i <= q; i ++){
            cin >> g[i] >> r[i] >> a[i];
            priority_queue<PII, vector<PII>, greater<PII>> pq;
            pq.push({0, g[i]});
            vector<int> vis(n+1), dis(n+1, 1e18);
            dis[g[i]] = 0;
            while(!pq.empty()){
                auto [dist, u] = pq.top();pq.pop();
                if(vis[u])continue;
                vis[u] = 1;
                for(auto v : adj[u]){
                    if(dis[u] + 1 < dis[v]){
                        dis[v] = dis[u]  +1;
                        pq.push({dis[v], v});
                    }
                }
            }
            auto check = [&](int x)->bool{
                int buy = 0, cost = a[i];
                for(auto v : shop){
                    auto [P, K, C] = v;
                    if(dis[C] <= x){
                        if(P*K <= cost)buy+=K, cost -=P*K;
                        else {
                            buy +=  cost/P;
                            break;
                        }
                    }
                }
                if(buy >= r[i])return true;
                else return false;
            };
            int l = 0, r = n;
            while(l < r){
                int mid = l + r >>1;
                if(check(mid))r = mid;
                else l = mid +1;  
            }
            if(l == n)cout << -1 << '\n';
            else cout << l << '\n';
        }
            
        
        
    }
    signed cute_prov0nce()
    {
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        // 取消同步流
        int t;
        //cin >> t;
        t = 1;
        while (t--)
        {
            solve();
        }

        return 0;
    }

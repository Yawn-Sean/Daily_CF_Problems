#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<PII> e;
    vector<vector<int>> g(n+m+1);
    for(int i = 1; i <= n;i ++){
        int k;
        cin >> k;
        for(int j = 1;  j <= k; j ++){
            int u;
            cin >> u;
            e.emplace_back(u, m + i);
        }
    }
    DSU dsu = DSU(n + m + 1);
    for(auto [u, v] : e){
        if(!dsu.same(u, v)){
            dsu.merge(u, v);
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
    }
    vector<int> p(n+m+1), depth(n+m+1);
    auto dfs = [&](auto &&dfs, int u, int fa)->void{
        depth[u] = depth[fa] + 1;
        p[u] = fa;
        for(auto v : g[u]){
            if(v != fa){
                dfs(dfs, v, u);
            }
        }
    };
    for(int i = 1; i <= m + n ; i ++){
        if(!depth[i]){
            dfs(dfs, i, 0);
        }
    }
    int q;
    cin >> q;
    while(q --){
        int x, y;
        cin >> x >> y;
        if(!dsu.same(x, y)){
            cout << -1 << '\n';
            continue;
        }
        vector<int> pathx, pathy;
        pathx.emplace_back(x);
        pathy.emplace_back(y);
        while(pathx.back() != pathy.back()){
            if(depth[pathx.back()] < depth[pathy.back()]){
                pathy.emplace_back(p[pathy.back()]);
            }
            else pathx.emplace_back(p[pathx.back()]);
        }
        cout << (pathx.size() + pathy.size())/2 << '\n';
        for(auto u : pathx){
            if(u > m)u-=m;
            cout << u << ' ';
        }
        for(int i = (int)pathy.size() - 2; i >= 0; i --){
            if(pathy[i] > m)pathy[i]-=m;
            cout << pathy[i] <<' ';
        }
        cout << '\n';
    }
}   
signed cute_prov0nce()
{   
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

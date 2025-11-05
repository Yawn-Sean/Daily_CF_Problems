#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 3e5 + 10;
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
vector<int> ve[1000005];
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> h(n), a;
    for(int i=0; i < n; i ++)cin >> h[i];
    vector<vector<int>> e(n);
    
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for(int i = 0; i < n; i ++)ve[h[i]].emplace_back(i);
    a = h;
    int ans = 1e18;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int mm = a.size();
    for(int i = 0; i < mm; i++){
        DSU dsu = DSU(n+1);
        for(int j = i; j < mm; j ++){
            for(auto v : ve[a[j]]){
                for(auto u : e[v]){
                    if(a[i] <= h[u] && h[u] <= a[j]){
                        if(!dsu.same(u, v))
                        dsu.merge(u, v);
                    }
                }
            }
            
            if(dsu.same(0, 1)){
                ans = min(ans, a[j]-a[i]);
                break;
            }
        }
    }
    cout << ans << '\n';
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

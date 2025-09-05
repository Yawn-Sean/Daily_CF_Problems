#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e3+10; 
const int mod = 1e9 + 7;
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
    DSU dsu1(n), dsu2(n);
    vector<array<int, 3>> g;
    for(int i = 0; i < m; i ++){
        int x, y;
        char c;
        cin >> x >> y >> c;
        x--;
        y--;
        int z;
        if(c == 'S')z = 0;
        else z = 1;
        if(z && !dsu1.same(x, y))dsu1.merge(x, y);
        g.push_back({x, y, z});
    }
    if((n&1) == 0){
        cout << -1 << '\n';
        return ;
    }
    vector<int> ans, vis(m);
    for(int i = 0 ;i < m;i ++){
        auto [x, y, z] = g[i];
        if(!z && !dsu1.same(x, y))dsu1.merge(x, y), ans.emplace_back(i), dsu2.merge(x, y), vis[i] = 1;
    }
    if((int)ans.size() > (n-1)/2){
        cout << -1 << '\n';
        return;
    }
    for(int i = 0 ;i  < m; i ++){
        auto [x, y, z] = g[i];
        if(!vis[i] && !z && !dsu2.same(x, y)){
            dsu2.merge(x, y);
            vis[i] = 1;
            ans.emplace_back(i);
        }
        if((int)ans.size() == (n-1)/2)break;
    }
    if((int)ans.size() < (n-1)/2){
        cout << -1 << '\n';
        return;
    }   
    for(int i = 0 ;i  < m; i ++){
        auto [x, y, z] = g[i];
        if(!vis[i] && z && !dsu2.same(x, y)){
            dsu2.merge(x, y);
            vis[i] = 1;
            ans.emplace_back(i);
        }
        if((int)ans.size() == (n-1))break;
    }
    if((int)ans.size() < (n-1)){
        cout << -1 << '\n';
        return;
    }
    cout << n-1 << '\n';
    for(auto u : ans)cout << u+1 << ' ';
}
signed cute_prov0nce()
{
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

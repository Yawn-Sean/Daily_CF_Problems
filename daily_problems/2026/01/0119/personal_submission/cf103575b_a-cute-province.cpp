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
    //考虑哪些奇边必须要, 有奇数个的话还要找一条奇边，这个奇边不能和奇边成环
    int n, m;
    cin >> n >> m; 
    vector<int> ans;
    vector<array<int, 3>> ve[2];
    vector<PII> idx(m+1);
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        idx[i] = {u, v};
        ve[w%2].push_back({u, v, i});
    }
    DSU dsu = DSU(n+1);
    for(auto v : ve[0]){
        if(!dsu.same(v[0], v[1])){
            dsu.merge(v[0], v[1]);
        }
    }
    int cnt2 = 0;
    array<int, 3> cnt1 = {-1, -1, -1};
    for(auto v : ve[1]){
        if(!dsu.same(v[0], v[1])){
            dsu.merge(v[0], v[1]);
            ans.emplace_back(v[2]);
            cnt2 ++ ;
        }
        else cnt1 = v;
    }
    if((cnt2 & 1)){
        if(cnt1[2] != -1){
            dsu = DSU(n+1);
        ans.emplace_back(cnt1[2]);
        for(auto i : ans){
            auto [u, v] = idx[i];
            dsu.merge(u, v);
        }
        //for(auto i : ans)cout << i << ' ';
        for(auto v : ve[0]){
            if(!dsu.same(v[0], v[1])){
                dsu.merge(v[0], v[1]);
                ans.emplace_back(v[2]);
            }
        }
        cout << "YES\n";
        for(auto i : ans)cout << i << ' ';
        cout << '\n';
        }
        else cout << "NO\n";
    }
    else{
        dsu = DSU(n+1);
        for(auto v : ve[0]){
            if(!dsu.same(v[0], v[1])){
                dsu.merge(v[0], v[1]);
                ans.emplace_back(v[2]);
            }
        }
        cout << "YES\n";
        for(auto i : ans)cout << i << ' ';
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

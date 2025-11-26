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
const int N = 2e5 + 10;
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
int dep[N], fa[N][20], h[N];
vector<PII> g[N];
void dfs(int u, int father){
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i =1 ; i <= 19; i ++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(auto [v, w] : g[u]){
		if(v != father){
            h[v] = h[u] + w;
            dfs(v, u);
        }
	}

}
int LCA(int u, int v){
	if(dep[u] < dep[v])swap(u, v);
	for(int i = 19; i >= 0; i --){
		if(dep[fa[u][i]] >= dep[v])u = fa[u][i];
	}
	if(u == v)return v;
	for(int i = 19; i >= 0; i --){
		if(fa[u][i] != fa[v][i])
		u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> ve, vv;
    DSU dsu = DSU(n+1);
    for(int i = 1; i <= n; i ++)g[i].clear();
    for(int i = 1; i<= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        ve.push_back({w, u, v});

    }
    sort(ve.begin(), ve.end());
    for(auto V : ve){
        int w = V[0], u = V[1], v = V[2];
        if(!dsu.same(u, v)){
            dsu.merge(u, v);
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }
        else vv.push_back({w, u, v});
    }
    dfs(1, 0);
    if(vv.size() != m-(n-1)){
        cout << "NO\n";
        return ;
    }
    for(auto V : vv){
        int w = V[0], u = V[1], v = V[2];
        int l = LCA(u, v);
        int len = h[u] + h[v] - 2*h[l];
        if(w < len){
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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

#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
int v[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
map<int, int> mp;
int f(int x){
    int res = 0;
    while(x%2 == 0){
        res ^= (1 << mp[x]);
        x/=2;
    }
    for(int i = 3; i * i <= x; i +=2){
        while(x%i == 0){
            res ^= (1 << mp[i]);
            x/=i;
        }
    }
    if(x > 1)res ^= (1 << mp[x]);
    return res;
}
int dep[N], fa[N][20];
vector<vector<int>> g(N);
void dfs(int u, int father){
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i =1 ; i <= 19; i ++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(auto v : g[u]){
		if(v != father)
		dfs(v, u);
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
//
void solve(){
    int n, q, L;
    cin >> n >> L;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i];
    vector<PII> dp(1 << 20, {20, -1});
    dp[0] = {0, L};
    for(int i = 0; i < (1 << 20); i ++){
        for(int j = 0; j < 20; j ++){
            if(((1 << j) & i) != 0){
                auto [v1, v2] = dp[(1 << j) ^ i];
                if(v2 * v[j] > L){
                    v1 ++;
                    v2 = min(v2, v[j]);
                }
                else v2 *= v[j];
                dp[i] = min(dp[i], {v1, v2});
            }
        }
    }
    vector<int> mask(n+1);
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    vector<int> st(n+1);
    for(int i = 1; i <= n; i++){
        st[i] = f(a[i]);
    }
    auto dfs1 = [&](auto &dfs1, int u, int fa)->void{
        mask[u] = mask[fa] ^ st[u];
        for(auto v : g[u]){
            if(v != fa){
                dfs1(dfs1, v, u);
            }
        }
    };
    dfs1(dfs1, 1, 0);
    dfs(1, 0);
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        int l = LCA(u, v);
        int sum = mask[u] ^ mask[v] ^ mask[l] ^ st[l] ^ mask[l];
        cout << dp[sum].x << '\n';
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
    for(int i = 0; i < 19; i ++)mp[v[i]] = i;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

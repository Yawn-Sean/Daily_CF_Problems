#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e5+10;
const int mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<vector<PII>> g(n);
    for(int i = 1; i <n ; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    vector<int> up_dp(n),down_dp(n), e(n), p(n);
    int ans = n, o1, o2 = -1;
    vector<PII> ve;
    auto dfs1 = [&](auto &dfs1, int u, int fa)->void{
    	p[u] = fa;
        for(auto [v,w] : g[u]){
            if(v != fa){
                dfs1(dfs1, v, u);
                down_dp[u] =  max(down_dp[u], down_dp[v] + 1);
            }
        }
    };
    
   	auto dfs2 = [&](auto &dfs2, int u, int fa)->void{
   		int v1 = up_dp[u], v2 = 0;
        for(auto [v,w] : g[u]){
            if(v != fa){
            	int val = down_dp[v] + 1;
				if (val > v1) swap(v1, v2), v1 = val;
				else if (val > v2) v2 = val;
            }
        }
        for(auto [v, w] : g[u]){
        	if(v != fa){
            	int val = down_dp[v] + 1;
				if (val == v1)up_dp[v] = v2 + 1;
				else up_dp[v] = v1 + 1;
                dfs2(dfs2, v, u);
            }
		}
    };
	dfs1(dfs1, 0, -1);
    dfs2(dfs2, 0, -1);
    for(int i = 0 ; i < n; i ++){
    	int res = max(up_dp[i], down_dp[i]);
    	if(i > 0)res = max(down_dp[i], up_dp[i]-1);
    	if(ans >= res){
    		ans = res;
    		o1 = i;
		}
	}
    auto df = [&](auto &df, int u, int fa)->void{
        
        for(auto [v, w] :g[u]){
            if(v != fa){
                e[v] = w;
                df(df, v, u);
            }
                
            }
        
    };
    
    for(auto [v, w] : g[o1]){
    	if(v == p[o1]){
    		e[o1] = w;
    		e[v] = w;
    		df(df, o1, v);
    		df(df, v, o1);
		}
	}
    cout << ans << '\n';
    for(int i = 0; i < n ; i++)cout << e[i] <<' ';
    cout << '\n';
}

signed cute_prov0nce() {
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e5 + 3;
const int N = 2e3 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    if(n >= 2002 || n % 2){
        cout << "impossible" << '\n';
    }
    else{
        vector<vector<int>> path(n+1, vector<int> (n+1));
        for(int i = 1; i <= m; i ++){
            int u, v;
            cin >> u>>v;
            path[u][v] = 1;
            path[v][u] = 1;
        }
        vector<int> col(n+1, -1), cnt(2), vv[2];
        vector<vector<vector<int>>> a(2);
        auto dfs = [&](auto &dfs, int u, int fa)->bool{
            if(fa == -1)col[u] = 0;
            else col[u] = col[fa] ^ 1;
            cnt[col[u]] ++;
            vv[col[u]].emplace_back(u);
            for(int v = 1; v <= n; v ++){
                if(v != u && !path[u][v]){
                    if(col[v] == -1 && !dfs(dfs, v, u) || col[v] == col[u])return false;
                }
            }
            return true;
        };
        vector<PII> ve;

        for(int i = 1;  i <= n; i ++){
            if(col[i] == -1){
                cnt.assign(2, 0);
                vv[0].clear();
                vv[1].clear();
                if(!dfs(dfs, i, -1)){
                    cout << "impossible" << '\n';
                    return ;
                }
                ve.emplace_back(cnt[0], cnt[1]);
                a[0].emplace_back(vv[0]);
                a[1].emplace_back(vv[1]);
            }
        }
        int m = ve.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        dp[0][0] = 1;
        for(int i = 1; i <= m; i ++){
            auto [x, y] = ve[i-1];
            for(int j = n; j >= 0; j --){
                if(j >= x)dp[i][j] |= dp[i-1][j-x];
                if(j >= y)dp[i][j] |= dp[i-1][j-y];
                //cout << dp[i][j] <<' ';
            }
            //cout << '\n' ;
        }
        if(!dp[m][n/2]){
            cout << "impossible" << '\n';
            return ;
        }
        vector<vector<int>> ans;
        int j = n/2, i = m;
        while(j && i > 0){
            auto [x, y] = ve[i-1];
            if(j-x >= 0 && dp[i-1][j-x]){
                j-=x;
                ans.emplace_back(a[0][i-1]);
                i--;
                continue;
            }
            if(j >= y && dp[i-1][j-y]){
                j-=y;
                ans.emplace_back(a[1][i-1]);
                i--;
                continue;
            }
        }
        vector<int> vis(n+1);
        for(auto v : ans){
            for(auto &u : v)vis[u] = 1;
        }
        for(int i = 1; i <= n; i ++){
            if(vis[i])cout << 'r' << '\n';
            else cout << 'b' << '\n';
        }
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

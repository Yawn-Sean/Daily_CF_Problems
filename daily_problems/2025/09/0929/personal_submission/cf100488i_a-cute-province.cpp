#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    set<PII> st;
    for(int i = 0 ; i < m ; i++){
        int u, v;
        cin >> u>> v;
        u--;
        v--;
        st.insert({u, v});
    }
    vector<vector<int>> g(n);
    vector<int> vis(n), color(n);
    for (int i = 0 ; i < n; i ++) {
        for (int j = 0 ;j < n; j ++)if (!st.count({i, j}) && !st.count({j, i}))g[i].emplace_back(j);
    }
    int s = 0, cnt = 1, sum = 0 ;
    auto dfs = [&](auto &dfs, int u)->void{
        vis[u] = 1;
        s ++;
        color[u] = cnt;
        for(auto v : g[u]){
            if(!vis[v])dfs(dfs, v);
        }
    };
    for(int i = 0; i < n; i ++){
        if(!vis[i]){
            s = 0;
            dfs(dfs, i);
            cnt++;
            sum += s * (s-1)/2;
        }
    }
    if(m !=n*(n-1)/2 - sum || k < cnt-1)cout << -1;
    else{
        for(int i = 0 ; i < n; i ++)cout << color[i] <<' ';
    }
    cout << '\n';
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

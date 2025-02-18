constexpr int MAXN = 1e5 + 1;
int in[MAXN] = {}, out[MAXN] = {};
int cnt = 0, ans = 0;
void dfs1(int cur, vector<vector<pll>> &adj, int fa){
    in[cur] = cnt++;
    for(auto it : adj[cur]){
        if(fa != it.fi)dfs1(it.fi, adj, cur);
    }
    out[cur] = cnt;
}
void dfs2(int cur, ll dis, vector<vector<pll>> &adj, vector<ll> &a, int fa){
    if(dis > a[cur]){
        ans += out[cur] - in[cur];
        return ;
    }
    for(auto it : adj[cur]){
        if(fa != it.fi)dfs2(it.fi, max(dis, 0LL) + it.se, adj, a, cur);
    }
}
int main(void){
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<pll>> adj(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        ll p, c;
        cin >> p >> c;p--;
        adj[i].push_back({p, c});
        adj[p].push_back({i, c});
    }
    dfs1(0, adj, -1);
    dfs2(0, 0, adj, a, -1);
    cout << ans << "\n";
}

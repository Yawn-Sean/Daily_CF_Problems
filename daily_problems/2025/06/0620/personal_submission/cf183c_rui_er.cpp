// P1477
const int N = 1e5 + 5;

int n, m, vis[N], val[N], ans;
vector<tuple<int, int>> e[N];

void dfs(int u, int c) {
    vis[u] = 1;
    val[u] = c;
    for(auto [v, w]: e[u]) {
        if(!vis[v]) dfs(v, c + w);
        else ans = __gcd(ans, abs((c + w) - val[v]));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m) {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v, +1);
        e[v].emplace_back(u, -1);
    }
    rep(i, 1, n) if(!vis[i]) dfs(i, 0);
    if(ans) cout << ans << endl;
    else cout << n << endl;
    return 0;
}

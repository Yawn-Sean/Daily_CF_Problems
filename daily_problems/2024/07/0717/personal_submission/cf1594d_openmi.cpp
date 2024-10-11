// 原本建的是单向图，不能跑全联通块，使得 多对1 时出现不正确的矛盾
// 双向图建立的关键在于考虑是否为同一队伍，而不是假定某一人为 crewmate 或者 imposters
void solve() {
    int n, m;
    cin >> n >> m;
    vvc<pii> g(n);
    vi role(n, -1);
    int a, b;
    string comment;
    rep (i, 0, m) {
        cin >> a >> b >> comment;
        a--, b--;
        g[a].emplace_back(b, comment == "crewmate");
        g[b].emplace_back(a, comment == "crewmate");
    }
    int cnt_person = 0;
    auto dfs = [&](auto&& dfs, int u) ->int{
        cnt_person += 1;
        int ans = !role[u];
        for (auto& [v, com]: g[u]) {
            // int vShouldBeC = role[u] ? com : (com ^ 1);
            int same_group = role[u] ? com : (com ^ 1);
            if (role[v] == -1) {
                role[v] = same_group;
                int t = dfs(dfs, v);
                if (t == -1) return -1;
                ans += t;
            } else if (role[v] != same_group) {
                return -1;
            }
        }
        return ans;
    };
    int ans = 0;
    rep (i, 0, n) {
        if (role[i] == -1) {
            cnt_person = 0;
            role[i] = 0;
            int cti = dfs(dfs, i);
            if (cti != -1) ans += max(cti, cnt_person - cti);
            else return cout << -1 << nl, void();
        }
    }
    cout << ans << nl;
}

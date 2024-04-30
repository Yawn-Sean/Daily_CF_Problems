void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i ++ ) {
        int a, b;
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int start = 0;
    unordered_set<int> neighbour;
    vector<bool> st(n + 1);
    function<vector<PII>(int, int)> dfs;

    dfs = [&](int cur, int lst) -> vector<PII> {
        // 选择当前节点作为环路节点
        if (neighbour.count(cur) && neighbour.size() == 2 || neighbour.size() < 2) return {};  // cur不能作为环路节点
        bool has_del = false;
        if (neighbour.count(cur)) neighbour.erase(cur), has_del = true;  // 从非环路节点中删除候选节点
        st[cur] = true;
        for (auto nxt: adj[cur]) {
            if (nxt == start && lst != -1 && lst != start) {
                // 找到一种可行方案
                return {{lst, cur}, {cur, start}};
            }
            if (nxt == lst || st[nxt]) continue;
            auto res = dfs(nxt, cur);
            if (!res.empty()) {
                if (lst != -1) res.emplace_back(lst, cur);
                return res;
            }
        }
        // 没有找到任何一种可行方案, 还原现场
        if (has_del) neighbour.insert(cur); 
        // st[cur] = false;
        return {};
    };

    for (int i = 1; i <= n; i ++ ) {
        if (adj[i].size() >= 4) {
            neighbour.clear();
            for (int j = 1; j <= n; j ++ ) st[j] = false;
            for (auto v: adj[i]) neighbour.insert(v);
            start = i;
            auto ans = dfs(i, -1);
            if (!ans.empty()) {
                cout << "YES\n" << ans.size() + 2 << "\n";
                for (auto [u, v]: ans) cout << u << ' ' << v << "\n";
                cout << *neighbour.begin() << ' ' << i << "\n";
                cout << *(++ neighbour.begin()) << ' ' << i << "\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt --) {
        solve();
    }
    return 0;
}

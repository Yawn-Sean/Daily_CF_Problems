/*
url: 
    question:   https://codeforces.com/problemset/problem/1056/D
    submission: https://codeforces.com/contest/1056/submission/261499106
time: 124 ms
*/

void solve() {
    int n;
    cin >> n;
    vector<int> cnt_leaf(n + 1);
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i ++ ) {
        int fa;
        cin >> fa;
        adj[fa].push_back(i);
    }
    for (int i = 1; i <= n; i ++ ) {
        if (adj[i].size() == 0) cnt_leaf[i] = 1;
    }
    auto dfs = [&](auto&& self, int i) -> void {
        for (auto nxt: adj[i]) {
            self(self, nxt);
            cnt_leaf[i] += cnt_leaf[nxt];
        }
    };
    dfs(dfs, 1);
    unordered_map<int, int> cnt;
    for (int i = 1; i <= n; i ++ ) {
        cnt[cnt_leaf[i]] ++;
    }
    int m = *max_element(cnt_leaf.begin(), cnt_leaf.end());
    for (int i = 1; i <= m; i ++ ) {
        for (int j = 0; j < cnt[i]; j ++ ) {
            cout << i << ' ';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}

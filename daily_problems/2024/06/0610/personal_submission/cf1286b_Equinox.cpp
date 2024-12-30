#include <bits/stdc++.h>

void solve() {
    int N, root;
    std::cin >> N;
    std::vector<std::vector<int>> g(N + 1);
    std::vector<int> cnt(N + 1);
    for (int i = 1, fa; i <= N; i ++ ) {
        std::cin >> fa >> cnt[i];
        if (fa) g[fa].push_back(i);
        else root = i;
    }
    std::vector<int> ans(N + 1);
    bool f = true;
    auto dfs = [&](auto&&self, int u) -> std::vector<int> {
        std::vector<int> son;
        for (int v : g[u])
            for (int x : self(self, v))
                son.push_back(x);
        std::sort(son.begin(), son.end(), [&](int x, int y) {
            return ans[x] < ans[y];
        });
        if (son.size() < cnt[u])
            f = false;
        else {
            for (int i = 0; i < cnt[u]; i ++ ) ans[son[i]] = i + 1;
            ans[u] = cnt[u] + 1;
            for (int i = cnt[u]; i < son.size(); i ++ ) ans[son[i]] = i + 2;
            son.push_back(u);
        }
        return son;
    };
    dfs(dfs, root);
    if (f) {
        std::cout << "YES\n";
        for (int i = 1; i <= N; i ++ ) std::cout << ans[i] << " \n"[i == N];
    }
    else
        std::cout << "NO\n";
}

int main(int argc, char** argv) {
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}
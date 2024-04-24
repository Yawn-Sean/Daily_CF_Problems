#include <bits/stdc++.h>

std::unordered_map<char, int> opmp = {{'A', 2}, {'O', 3}, {'X', 4}, {'N', 5}};
int main() {
    int n, cntin = 0;
    std::cin >> n;
    std::vector<int> ops(n), val(n), change(n, 0);
    std::vector<std::vector<int>> children(n);
    for (int i = 0; i < n; i++) {
        std::string op;
        int v1, v2;
        std::cin >> op >> v1;
        if (op[0] == 'I') ops[i] = v1, cntin++;
        else if (op[0] == 'N') {
            ops[i] = opmp[op[0]];
            children[i].push_back(v1 - 1);
        } else {
            std::cin >> v2;
            ops[i] = opmp[op[0]];
            children[i].push_back(v1 - 1);
            children[i].push_back(v2 - 1);
        }
    }

    // 计算每个节点的值
    std::function<int(int)> dfs = [&](int u) {
        if (ops[u] == 2) return val[u] = dfs(children[u][0]) & dfs(children[u][1]);
        else if (ops[u] == 3) return val[u] = dfs(children[u][0]) | dfs(children[u][1]);
        else if (ops[u] == 4) return val[u] = dfs(children[u][0]) ^ dfs(children[u][1]);
        else if (ops[u] == 5) return val[u] = !dfs(children[u][0]);
        return val[u] = ops[u];
    };
    dfs(0);

    std::queue<int> q;
    q.emplace(0);
    // 计算每个节点是否会改变根的值
    while (!q.empty()) {
        int u = q.front();
        change[u] = 1;
        q.pop();
        if (ops[u] == 2) {
            int v = children[u][0], w = children[u][1];
            if (val[u]) { q.emplace(v); q.emplace(w); } 
            else if (val[v]) q.emplace(w);
            else if (val[w]) q.emplace(v);
        } else if (ops[u] == 3) {
            int v = children[u][0], w = children[u][1];
            if (!val[u]) { q.emplace(v); q.emplace(w); } 
            else if (!val[v]) q.emplace(w);
            else if (!val[w]) q.emplace(v);
        } else if (ops[u] == 4) {
            q.emplace(children[u][0]);
            q.emplace(children[u][1]);
        } else if (ops[u] == 5) {
            q.emplace(children[u][0]);
        }
    }

    std::string ans(cntin, '0');
    for (int i = 0, j = 0; i < n; i++) {
        if (ops[i] < 2) {
            ans[j++] = '0' + (change[i] ? !val[0] : val[0]);
        }
    }
    std::cout << ans << '\n';
    return 0;
}

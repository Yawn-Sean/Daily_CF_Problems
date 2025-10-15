/*
必须按照某种 DFS 的顺序才行
数据范围很小，考虑预处理出所有的以 u 为根的子树的叶子有哪些
对于以 u 为根的所有叶子，它们应该是在访问顺序中连续出现的
枚举所有的 u，都应该满足这个条件才行
在判断了可行性之后，直接暴力行走即可
*/

vector<vector<int>> e(N);
int n;
vector<int> order;
vector<vector<int>> leaves(N);
vector<int> path;
bool ok = false;
bool first_time = true;

void dfs(int u, int fa) {
    bool is_leaf = true;
    for (auto v : e[u]) {
        if (v != fa) {
            dfs(v, u);
            is_leaf = false;
            for (auto vv : leaves[v]) {
                leaves[u].push_back(vv);
            }
        }
    }
    if (is_leaf) {
        leaves[u].push_back(u);
    }
}

void walk(int u, int fa, int target) {
    path.push_back(u);
    if (u == target) {
        ok = true;
        if (first_time) {
            first_time = false;
            for (auto v : path) {
                cout << v << " ";
            }
        } else {
            for (int i = 1; i < path.size(); i++) {
                cout << path[i] << " ";
            }
        }
        return;
    }

    for (auto v : e[u]) {
        if (v != fa) {
            walk(v, u, target);
            if (ok) {
                break;
            }
        }
    }
    path.pop_back();
}

void find_path(int u, int v) {
    path.clear();
    ok = false;
    walk(u, 0, v);
}

void meibao() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        order.push_back(u);
    }

    dfs(1, 0);

    auto check = [&] (int u) -> bool {
        set<int> s;
        for (auto v : leaves[u]) {
            s.insert(v);
        }

        for (int i = 0; i < order.size(); i++) {
            if (s.count(order[i])) {
                for (int j = i; j < order.size(); j++) {
                    if (s.count(order[j])) {
                        s.erase(order[j]);
                    } else {
                        break;
                    }
                }
                if (s.size() != 0) {
                    return false;
                }
                break;
            }
        }
        return true;
    };

    for (int i = 1; i <= n; i++) {
        if (!check(i)) {
            cout << "-1\n";
            return;
        }
    }

    int cur = 1;
    for (int i = 0; i < order.size(); i++) {
        int v = order[i];
        find_path(cur, v);
        cur = v;
    }
    find_path(cur, 1);
}

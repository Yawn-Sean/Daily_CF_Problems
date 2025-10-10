#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // 预筛小质数到 40000（覆盖 sqrt(1e7)）
    const int LIM = 40000;
    std::vector<int> primes;
    std::vector<bool> is_composite(LIM + 1, false);
    for (int i = 2; i <= LIM; i++) {
        if (!is_composite[i]) {
            primes.push_back(i);
            if ((i64)i * i <= LIM) {
                for (int j = i * i; j <= LIM; j += i) {
                    is_composite[j] = true;
                }
            }
        }
    }

    // 每个点的唯一质因子集合；及全局质数出现次数
    std::vector<std::vector<int>> facs(n + 1);
    std::unordered_map<int, int> cnt;
    cnt.reserve(n * 2);
    cnt.max_load_factor(0.7f);

    for (int i = 1; i <= n; i++) {
        int x = a[i];
        for (int p : primes) {
            if ((i64)p * p > x) {
                break;
            }
            if (x % p == 0) {
                facs[i].push_back(p);
                while (x % p == 0) {
                    x /= p;
                }
            }
        }
        if (x > 1) {
            facs[i].push_back(x);
        }
        // 去重（理论上已唯一，但稳妥起见）
        std::sort(facs[i].begin(), facs[i].end());
        facs[i].erase(std::unique(facs[i].begin(), facs[i].end()), facs[i].end());
        for (int p : facs[i]) {
            cnt[p] += 1;
        }
    }

    // 候选质数：出现次数 > n/2
    std::vector<int> candidates;
    candidates.reserve(16);
    for (const auto &kv : cnt) {
        if (kv.second > n / 2) {
            candidates.push_back(kv.first);
        }
    }
    if (candidates.empty()) {
        std::cout << "NO\n";
        return 0;
    }

    // 为多次 BFS 复用的结构（token 技巧避免 O(n) 清空）
    std::vector<int> dist(n + 1, 0);
    std::vector<int> seen_token(n + 1, 0);
    int cur_token = 0;

    auto bfs_farthest = [&](int start, const std::vector<char> &mark, std::vector<int> *visited_list) {
        cur_token++;
        std::queue<int> q;
        q.push(start);
        seen_token[start] = cur_token;
        dist[start] = 0;

        if (visited_list != nullptr) {
            visited_list->clear();
            visited_list->push_back(start);
        }

        int best_node = start;
        int best_dist = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] > best_dist) {
                best_dist = dist[u];
                best_node = u;
            }
            for (int v : g[u]) {
                if (mark[v] && seen_token[v] != cur_token) {
                    seen_token[v] = cur_token;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if (visited_list != nullptr) {
                        visited_list->push_back(v);
                    }
                }
            }
        }
        return std::pair<int,int>{best_node, best_dist};
    };

    std::vector<char> used(n + 1, 0);
    std::vector<char> mark(n + 1, 0);
    std::vector<int> comp_nodes;
    comp_nodes.reserve(n);

    for (int p : candidates) {
        // 标记被 p 整除的点
        std::vector<int> nodes;
        nodes.reserve(cnt[p]);
        for (int i = 1; i <= n; i++) {
            mark[i] = 0;
            used[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            // facs[i] 很短（<= ~8）
            bool ok = false;
            for (int f : facs[i]) {
                if (f == p) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                mark[i] = 1;
                nodes.push_back(i);
            }
        }
        // 对每个连通分量做两次 BFS 求直径
        for (int u : nodes) {
            if (!used[u]) {
                // 第一次 BFS：拿到该分量所有节点（visited_list）和最远点 s
                auto pr1 = bfs_farthest(u, mark, &comp_nodes);
                int s = pr1.first;
                for (int v : comp_nodes) {
                    used[v] = 1;
                }
                // 第二次 BFS：从 s 出发求分量直径
                auto pr2 = bfs_farthest(s, mark, nullptr);
                int diameter_edges = pr2.second;
                int diameter_nodes = diameter_edges + 1;
                if (diameter_nodes > n / 2) {
                    std::cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "NO\n";
    return 0;
}

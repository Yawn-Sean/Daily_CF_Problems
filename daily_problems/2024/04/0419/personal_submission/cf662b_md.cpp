#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e8;
struct DSU {
    vector<int> m_parent, m_siz;
    DSU(int n) : m_parent(n), m_siz(n, 1) { iota(begin(m_parent), end(m_parent), 0); }
    int leader(int u) {
        while (u != m_parent[u]) { u = m_parent[u] = m_parent[m_parent[u]]; } 
        return u;
    }
    bool merge(int x, int y) {
        x = leader(x); y = leader(y);
        if (x == y) { return false; }
        if (m_siz[x] < m_siz[y]) { swap(x, y);}
        m_parent[y] = x;
        m_siz[x] += m_siz[y];
        return true;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    vector<tuple<int, int, char>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        edges.emplace_back(u - 1, v - 1, c);
    }

    auto check = [&](char to_flip) -> pair<int, vector<int>> {
        DSU dsu(n * 2);
        for (auto[u, v, c] : edges) {
            if (c == to_flip) {
                dsu.merge(u, v + n);
                dsu.merge(v, u + n);
            } else {
                dsu.merge(u, v);
                dsu.merge(u + n, v + n);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dsu.leader(i) == dsu.leader(i + n)) {
                return {inf, {}};
            }
        }

        map<int, vector<int>> groups_keep;
        map<int, vector<int>> groups_if_flipped;
        for (int i = 0; i < n; ++i) {
            groups_keep[dsu.leader(i + n)].push_back(i + 1);
            groups_if_flipped[dsu.leader(i)].push_back(i + 1);
        }

        deque<bool> visited(n * 2, false);
        vector<int> actions;
        for (int i = 0; i < n; ++i) {
            int x = dsu.leader(i);
            if (!visited[x]) {
                if (size(groups_keep[x]) < size(groups_if_flipped[x])) {
                    actions.insert(end(actions), begin(groups_keep[x]), end(groups_keep[x]));
                } else {
                    actions.insert(end(actions), begin(groups_if_flipped[x]), end(groups_if_flipped[x]));
                }
                visited[x] = true;
                visited[dsu.leader(i + n)] = true;
            }
        }
        return {size(actions), actions};
    };

    auto ans_B = check('R');
    auto ans_R = check('B');
    auto& ans = ans_B.first < ans_R.first ? ans_B : ans_R;
    if (ans.first == inf) {
        cout << -1 << "\n";
    } else {
        [](int ans, const vector<int>& actions) {
            cout << ans << "\n";
            for (auto act : actions) {
                cout << act << " ";
            }
            cout << "\n";
        } (ans.first, ans.second);
    }

    return 0;
}
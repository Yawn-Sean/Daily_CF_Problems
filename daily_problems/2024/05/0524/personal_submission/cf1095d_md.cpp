// 0524
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<array<int, 2>> nxt(n, array<int, 2>());
    for (int i = 0; i < n; ++i) {
        cin >> nxt[i][0] >> nxt[i][1];
        --nxt[i][0];
        --nxt[i][1];
    }

    map<pair<int, int>, vector<pair<int, int>>> edgeToGroups;
    map<pair<int, int>, vector<pair<int, int>>> options;
    for (int i = 1; i < n; ++i) {
        for (int g = 0; g < 2; ++g) {
            options[{i, g}].push_back({i, nxt[i][g]});
            options[{i, g}].push_back({nxt[i][g], nxt[i][g ^ 1]});
            edgeToGroups[{i, nxt[i][g]}].push_back({i, g});
            edgeToGroups[{nxt[i][g], nxt[i][g ^ 1]}].push_back({i, g});
        }
    }

    auto check = [&](int k) -> vector<int> {
        vector<int> pos(n, -1);
        deque<int> visited(n, false);
        pos[0] = nxt[0][k];
        visited[0] = true;
        
        int edge_cnt = 1;
        int cur_idx = 0;
        pair<int, int> cur_edge = {0, nxt[0][k]};
        while (edge_cnt < n) {
            if (edgeToGroups.contains(cur_edge)) {
                auto last_edge = cur_edge;
                const auto& coords = edgeToGroups[cur_edge];
                for (const auto& [idx, g] : coords) {
                    if (visited[idx]) {
                        continue;
                    }
                    for (auto[u, v] : options[{idx, g}]) {
                        if (last_edge.first == u && last_edge.second == v) {
                            continue;
                        }
                        cur_edge = {u, v};
                        pos[u] = v;
                        edge_cnt++;
                    }
                    visited[idx] = true;
                    break;
                }
            } else {
                break;
            }
        }
        return pos;
    };

    auto pos1 = check(0);
    auto pos2 = check(1);

    if (count(begin(pos1), end(pos1), -1) == 0) {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cout << cur + 1 << " ";
            cur = pos1[cur];
        }
    } else {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cout << cur + 1 << " ";
            cur = pos2[cur];
        }
    }

    return 0;
}

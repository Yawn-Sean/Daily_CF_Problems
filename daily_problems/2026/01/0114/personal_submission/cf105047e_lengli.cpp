#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<pair<int,int>> ops;
    ops.reserve(2500);

    auto myswap = [&](int i, int j) {
        assert(a[i] == 0 || a[j] == 0);
        if (a[i] == 0) {
            ops.emplace_back(i, j);
            ops.emplace_back(j, i);
        } else {
            ops.emplace_back(j, i);
            ops.emplace_back(i, j);
        }
        swap(a[i], a[j]);
    };

    // 将 a 中的某个位置置零
    {
        vector<int> indices;
        for (int mask = 1; mask < (1 << 21); ++mask) {
            int xor_sum = 0;
            indices.clear();
            for (int i = 0; i <= 20; ++i) {
                if (mask & (1 << i)) {
                    xor_sum ^= a[i + 1];
                    indices.push_back(i + 1);
                }
            }
            if (xor_sum == 0) {
                int first = indices[0];
                for (int i = 1; i < (int)indices.size(); ++i) {
                    a[first] ^= a[indices[i]];
                    ops.emplace_back(first, indices[i]);
                }
                assert(a[first] == 0);
                if (first != 1) myswap(1, first);
                assert(a[1] == 0);
                break;
            }
        }
    }

    // 构建目标位置映射
    vector<int> target_pos(n + 1);
    vector<int> sorted_a(a.begin() + 1, a.end());
    sort(sorted_a.begin(), sorted_a.end());
    unordered_map<int, queue<int>> value_pos;
    for (int i = 0; i < n; ++i) {
        value_pos[sorted_a[i]].push(i + 1);
    }
    for (int i = 1; i <= n; ++i) {
        target_pos[i] = value_pos[a[i]].front();
        value_pos[a[i]].pop();
    }

    // 遍历每个未访问位置，执行置零+异或操作
    vector<bool> visited(n + 1, false);
    vector<int> cycle;
    auto process_cycle = [&](int start) {
        cycle.clear();
        int u = start;
        while (!visited[u]) {
            cycle.push_back(u);
            visited[u] = true;
            u = target_pos[u];
        }

        if (cycle.size() == 1) return;
        if (cycle.size() == 2) {
            ops.emplace_back(cycle[0], cycle[1]);
            a[cycle[0]] ^= a[cycle[1]];
            ops.emplace_back(cycle[1], cycle[0]);
            a[cycle[1]] ^= a[cycle[0]];
            ops.emplace_back(cycle[0], cycle[1]);
            a[cycle[0]] ^= a[cycle[1]];
            return;
        }

        myswap(1, cycle[0]);
        int zero_pos = cycle[0];
        cycle[0] = 1;

        for (int i = (int)cycle.size() - 1; i >= 0; --i) {
            myswap(zero_pos, cycle[i]);
            zero_pos = cycle[i];
        }
    };

    for (int i = 2; i <= n; ++i) {
        if (!visited[i]) process_cycle(i);
    }

    assert(is_sorted(a.begin() + 1, a.end()));
    assert(ops.size() <= 2500);

    cout << ops.size() << '\n';
    for (auto &[x, y] : ops) {
        cout << x << ' ' << y << '\n';
    }

    return 0;
}

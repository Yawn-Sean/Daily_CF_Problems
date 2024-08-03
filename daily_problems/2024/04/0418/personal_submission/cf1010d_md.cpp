#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::map<string, int> str2type = {
        {"IN", 0}, {"NOT", 1}, {"AND", 2}, {"OR", 3}, {"XOR", 4}
    };

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> children(n + 1);
    std::vector<int> types(n + 1, -1);
    vector<int> inIdx;
    for (int i = 1; i <= n; ++i) {
        std::string type;
        cin >> type;
        if (type == "IN" || type == "NOT") {
            int x;
            cin >> x;
            children[i].push_back(x);
            if (type == "IN") {
                inIdx.push_back(i);
            }
        } else {
            int x, y;
            cin >> x >> y;
            children[i].push_back(x);
            children[i].push_back(y);
        }
        types[i] = str2type.at(type);
    }

    std::deque<bool> fixed(n + 1, false);
    auto dfs = [&](auto self, int cur) {
        if (types[cur] == 0) { 
            return children[cur][0]; 
        }

        std::vector<int> children_vals;
        std::transform(begin(children[cur]), end(children[cur]), back_inserter(children_vals), [&](auto x) {
            return self(self, x);
        });

        if (types[cur] == 1) {
            return children_vals[0] ^ 1;
        } else if (types[cur] == 2) {
            for (int i = 0; i < 2; ++i) {
                fixed[children[cur][1 ^ i]] = static_cast<bool>(1 ^ children_vals[i]);
            }
            return children_vals[0] & children_vals[1];
        } else if (types[cur] == 3) {
            for (int i = 0; i < 2; ++i) {
                fixed[children[cur][1 ^ i]] = static_cast<bool>(children_vals[i]);
            }
            return children_vals[0] | children_vals[1];
        } else {
            return children_vals[0] ^ children_vals[1];
        }
    };

    const auto init_val = dfs(dfs, 1);

    auto spread = [&](auto self, int cur) {
        if (types[cur] == 0) { return; }

        for (int i = 0; i < size(children[cur]); ++i) {
            if (fixed[cur]) {
                fixed[children[cur][i]] = true;
            }
            self(self, children[cur][i]);
        }
    };

    spread(spread, 1);

    std::string ret(size(inIdx), '0');
    std::transform(begin(inIdx), end(inIdx), begin(ret), [init_val, &fixed](auto idx) {
        return fixed[idx] ? (init_val + '0') : ((1 ^ init_val) + '0');
    });

    std::cout << ret << endl;
    return 0;
}
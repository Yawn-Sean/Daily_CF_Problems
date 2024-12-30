// 0618
#include <bits/stdc++.h>

constexpr int inf = 1e8;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;;
    int n;
    std::cin >> n;
    std::array<std::array<int, 26>, 26> convert{};
    for (auto& cv : convert) {
        std::fill(begin(cv), end(cv), -1);
    }

    for (int i = 0; i < 26; ++i) {
        convert[i][i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        char from, to;
        int cost;
        std::cin >> from >> to >> cost;
        auto& val = convert[from - 'a'][to - 'a'];
        if (val != -1) {
            val = std::min(val, cost);
        } else {
            val = cost;
        }
    }

    if (size(a) != size(b)) {
        std::cout << "-1\n";
        return 0;
    }

    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (convert[i][k] != -1 && convert[k][j] != -1) {
                    if (convert[i][j] == -1) {
                        convert[i][j] = convert[i][k] + convert[k][j];
                    } else {
                        convert[i][j] = std::min(convert[i][j], convert[i][k] + convert[k][j]);
                    }
                }
            }
        }
    }

    std::string ret {};
    int cost {0};
    for (size_t i = 0; i < size(a); ++i) {
        if (a[i] == b[i]) {
            ret += a[i];
            continue;
        }

        char cur_char = '#';
        int cur_cost = inf;
        for (int interm = 0; interm < 26; ++interm) {
            int costa = convert[a[i] - 'a'][interm];
            int costb = convert[b[i] - 'a'][interm];
            if (costa != -1 && costb != -1) {
                if (costa + costb < cur_cost) {
                    cur_cost = costa + costb;
                    cur_char = static_cast<char>('a' + interm);
                }
            }
        }

        if (cur_char == '#') {
            std::cout << "-1\n";
            return 0;
        }
        cost += cur_cost;
        ret += cur_char;
    }

    std::cout << cost << '\n' << ret << '\n';

    return 0;
}
// 0515
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::copy_n(istream_iterator<int>(std::cin), n, begin(a));

    auto get_max_streak = [&](int target) {
        int max_streak = 0;
        std::optional<int> streak = std::nullopt;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] == target) {
                if (!streak.has_value()) {
                    streak = 2;
                } else {
                    streak.value()++;
                }
            } else {
                max_streak = max(max_streak, streak.value_or(0));
                streak = std::nullopt;
            }
        }
        return max_streak;
    };
    const int max_streak = max(get_max_streak(1), get_max_streak(-1));

    std::optional<int> y = std::nullopt;
    for (int i = 1; i < n; ++i) {
        auto diff = abs(a[i] - a[i - 1]);
        if (diff == 1) {
            continue;
        }

        if (diff == 0 || diff < max_streak || y.has_value() && diff != y.value()) {
            std::cout << "NO" << std::endl;
            return 0;
        }

        if (!y.has_value()) {
            y = diff;
        }
    }

    const int max_val = *std::max_element(begin(a), end(a));
    auto width = y.value_or(max_val);
    auto height = (max_val + width - 1) / width;
    if (width > 1e9 || height > 1e9) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    auto get_coord = [width](int id) -> pair<int, int> {
        int x = (id - 1) / width;
        int y = (id - 1) % width;
        return make_pair(x, y);
    };

    for (int i = 1; i < n; ++i) {
        auto[x1, y1] = get_coord(a[i - 1]);
        auto[x2, y2] = get_coord(a[i]);
        if (abs(x1 - x2) + abs(y1 - y2) != 1) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
    std::cout << height << " " << width << std::endl;
    return 0;
}
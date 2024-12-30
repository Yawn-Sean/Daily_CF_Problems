// 0511
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;
constexpr int inf = 1e9 + 5;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<tuple<int, int, int, int>> rects(n);
    for (int i = 0; i < n; ++i) {
        cin >> get<0>(rects[i]) >> get<1>(rects[i]) >> get<2>(rects[i]) >> get<3>(rects[i]);
    }

    auto prefix = rects;
    for (int i = 1; i < n; ++i) {
        const auto[x1, y1, x2, y2] = rects[i];
        const auto[last_px1, last_py1, last_px2, last_py2] = prefix[i - 1];
        auto&[px1, py1, px2, py2] = prefix[i];
        px1 = max(last_px1, x1);
        px2 = min(last_px2, x2);
        py1 = max(last_py1, y1);
        py2 = min(last_py2, y2);
    }
    
    auto suffix = rects;
    for (int i = n - 2; i >= 0; --i) {
        const auto[x1, y1, x2, y2] = rects[i];
        const auto[prev_px1, prev_py1, prev_px2, prev_py2] = suffix[i + 1];
        auto&[px1, py1, px2, py2] = suffix[i];
        px1 = max(prev_px1, x1);
        px2 = min(prev_px2, x2);
        py1 = max(prev_py1, y1);
        py2 = min(prev_py2, y2);
    }

    auto cando = [](auto& prefix, int idx) -> bool {
        return get<0>(prefix[idx]) <= get<2>(prefix[idx]) && get<1>(prefix[idx]) <= get<3>(prefix[idx]);
    };

    if (cando(prefix, n - 2)) {
        cout << get<0>(prefix[n - 2]) << " " << get<1>(prefix[n - 2]) << '\n';
        return 0;
    } else if (cando(suffix, 1)) {        
        cout << get<0>(suffix[1]) << " " << get<1>(suffix[1]) << '\n';
        return 0;
    } else {        
        auto check_x = [&](int idx) -> bool {
            return max(get<0>(prefix[idx - 1]), get<0>(suffix[idx + 1])) <= min(get<2>(prefix[idx - 1]), get<2>(suffix[idx + 1]));
        };
        auto check_y = [&](int idx) -> bool {
            return max(get<1>(prefix[idx - 1]), get<1>(suffix[idx + 1])) <= min(get<3>(prefix[idx - 1]), get<3>(suffix[idx + 1]));
        };
        for (int i = 1; i <= n - 2; ++i) {
            if (check_x(i) && check_y(i)) {
                cout << max(get<0>(prefix[i - 1]), get<0>(suffix[i + 1])) << " " << max(get<1>(prefix[i - 1]), get<1>(suffix[i + 1])) << '\n';
                return 0;
            }
        }
    }
    
    return 0;
}
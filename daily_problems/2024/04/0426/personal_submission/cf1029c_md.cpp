#include <bits/stdc++.h>
using namespace std;

using pii = std::pair<int, int>;
constexpr int inf = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    vector<pii> segs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> segs[i].first >> segs[i].second;
    }

    vector<int> prefix_left_max(n, -inf);
    vector<int> prefix_right_min(n, inf);

    for (int i = 1; i < n; ++i) {
        prefix_left_max[i] = max(prefix_left_max[i - 1], segs[i - 1].first);
        prefix_right_min[i] = min(prefix_right_min[i - 1], segs[i - 1].second);
    }
    
    int suffix_left_max = -inf;
    int suffix_right_min = inf;
    int ret = 0;
    for (int i = n - 1; i >= 0; --i) {
        ret = max(ret, min(suffix_right_min, prefix_right_min[i]) - max(suffix_left_max, prefix_left_max[i]));
        suffix_right_min = min(suffix_right_min, segs[i].second);
        suffix_left_max = max(suffix_left_max, segs[i].first);
    }

    cout << ret << '\n';

    return 0;
}
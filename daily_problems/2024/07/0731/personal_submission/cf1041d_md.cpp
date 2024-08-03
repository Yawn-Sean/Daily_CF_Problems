// 0731
#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    i64 h;
    std::cin >> n >> h;
    std::vector<pii> segs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> segs[i].first >> segs[i].second;
    }

    std::vector<i64> seg_acc(n);
    // find height diffs
    for (int i = 1; i < n; ++i) {
        seg_acc[i] = segs[i].first - segs[i-1].second;
    }

    std::partial_sum(begin(seg_acc), end(seg_acc), begin(seg_acc));

    i64 dis = 0;
    for (int i = 0; i < n; ++i) {
        auto pos = std::lower_bound(begin(seg_acc) + i, end(seg_acc), h + seg_acc[i]) - begin(seg_acc);
        dis = std::max(dis, segs[pos-1].second - segs[i].first + h - (seg_acc[pos-1] - seg_acc[i]));
    }

    std::cout << dis << '\n';

    return 0;
}
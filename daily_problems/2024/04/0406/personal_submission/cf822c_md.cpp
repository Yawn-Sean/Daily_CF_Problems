#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    vector<tuple<int, int, int>> data;
    data.reserve(n);
    for (int i = 0; i < n; ++i) {
        int l, r, cost;
        tuple<int, int, int> vals;
        cin >> get<0>(vals) >> get<1>(vals) >> get<2>(vals);   
        data.emplace_back(move(vals));
    }

    sort(begin(data), end(data));

    // len + sorted by l can ensure values in left_segs[len] are non-decreasing
    vector<vector<pair<int, int>>> left_segs(2e5 + 100);
    int ret = INT_MAX;

    for (auto[l, r, cost] : data) {
        auto len = r - l + 1;
        if (len >= x) { continue; }

        auto& target_segs = left_segs[x - len];
        auto it = lower_bound(begin(target_segs), end(target_segs), l, [&](auto&& elem, int val) {
            return elem.first < val;
        });

        if (it != begin(target_segs)) {
            --it;
            ret = min(ret, cost + it->second);
        }

        auto& left_seg = left_segs[len];
        if (empty(left_seg)) {
            left_seg.emplace_back(r, cost);
        } else {
            left_seg.emplace_back(r, min(left_seg.back().second, cost));
        }
    }

    cout << (ret == INT_MAX ? -1 : ret) << "\n";
    return 0;
}
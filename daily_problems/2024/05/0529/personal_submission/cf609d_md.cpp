// 0529
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k, s;
    std::cin >> n >> m >> k >> s;
    vector<int> to_usd(n);
    copy_n(istream_iterator<int>(std::cin), n, begin(to_usd));
    vector<int> to_gbp(n);
    copy_n(istream_iterator<int>(std::cin), n, begin(to_gbp));

    vector<pii> items;
    items.reserve(m);
    for (int i = 0; i < m; ++i) {
        int type, value;
        cin >> type >> value;
        items.emplace_back(type, value);
    } 

    auto get_sorted_min_items = [&](const int max_days) -> vector<tuple<i64, int, int>> {
        auto min_usd_rate = min_element(begin(to_usd), begin(to_usd) + max_days + 1);
        auto min_gbp_rate = min_element(begin(to_gbp), begin(to_gbp) + max_days + 1);

        vector<tuple<i64, int, int>> costs;
        costs.reserve(m);
        for (size_t i = 0; i < size(items); ++i) {
            auto[type, val] = items[i];
            if (type == 1) {
                costs.emplace_back(1ll * val * (*min_usd_rate), i + 1, min_usd_rate - begin(to_usd) + 1);
            } else {
                costs.emplace_back(1ll * val * (*min_gbp_rate), i + 1, min_gbp_rate - begin(to_gbp) + 1);
            }
        }

        nth_element(begin(costs), begin(costs) + k, end(costs));
        // sort(begin(costs), end(costs));
        return costs;
    };

    auto check = [&](const int max_days) -> bool {
        const auto costs = get_sorted_min_items(max_days);
        i64 total_cost = accumulate(cbegin(costs), cbegin(costs) + k, 0ll, [](i64 acc, const auto& p) {
            return acc + std::get<0>(p);
        });
        
        return total_cost <= static_cast<i64>(s);
    };

    int lo = 0;
    int hi = n - 1;
    while (lo + 1 < hi) {
        auto mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }

    int ans = -1;
    if (check(lo)) {
        cout << lo + 1 << '\n';
        ans = lo;
    } else if (check(hi)) {
        ans = hi;
        cout << hi + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }

    if (ans != -1) {        
        const auto sorted_items = get_sorted_min_items(ans);
        for (const auto&[_, idx, day] : sorted_items | ranges::views::take(k)) {
            cout << idx << ' ' << day << endl;
        }
    }

    return 0;
}

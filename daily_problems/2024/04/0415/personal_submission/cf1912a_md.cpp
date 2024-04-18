#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x, k;
    std::cin >> x >> k;
    vector<pair<i64, i64>> to_add;

    for (int t = 0; t < k; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        copy_n(istream_iterator<int>(cin), n, begin(a));
    
        i64 prefix = 0;
        i64 min_prefix = 0;
        i64 last_max_prefix = 0;
        for (auto num : a) {
            prefix += num;
            min_prefix = max(min_prefix, -prefix);
                    
            if (prefix > last_max_prefix) {
                to_add.emplace_back(min_prefix, prefix - last_max_prefix);
                last_max_prefix = prefix;
            }
        }
    }

    sort(begin(to_add), end(to_add));

    for (auto[min_prefix, delta] : to_add) {
        if (x >= min_prefix) {
            x += delta;
        }
    }
    std::cout << x << std::endl;

    return 0;
}
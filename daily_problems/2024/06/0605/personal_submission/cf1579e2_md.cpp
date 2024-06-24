// 0605
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n = 0) : n(n), a(n, T()) {}
    
    // set num[x] = v
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }

    // sum of [0, x)    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));

    auto nums_copy {nums};
    std::sort(begin(nums), end(nums));
    nums.erase(std::unique(begin(nums), end(nums)), end(nums));
    auto get_id = [&](int val) {
        return std::lower_bound(begin(nums), end(nums), val) - begin(nums);
    };

    Fenwick<int> fen {size(nums) + 1};
    i64 ret {0};
    for (int i = 0; i < n; ++i) {
        const int id = get_id(nums_copy[i]);
        ret += std::min(fen.sum(id), i - fen.sum(id + 1));
        fen.add(id, 1);
    }

    std::cout << ret << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
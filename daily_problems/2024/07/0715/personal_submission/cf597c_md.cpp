// 0716
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) : a(n, T()), n(n){}
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
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
    // rangeSum [l, r)
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
        --nums[i];
    }

    Fenwick<i64> fen(n);
    std::vector<i64> dp(n, 1);
    for (int l = 0; l < k; ++l) {
        fen.init(n);
        for (int i = 0; i < n; ++i) {
            fen.add(nums[i], dp[i]);
            dp[i] = fen.sum(nums[i]);
        }
    }

    std::cout << std::accumulate(begin(dp), end(dp), 0ll) << '\n';
    return 0;
}
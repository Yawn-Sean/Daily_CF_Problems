// 0708
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> nums(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, begin(nums));
    std::transform(begin(nums), end(nums), begin(nums), [](int x) {
        return x - 1;
    });

    std::vector<int> freq(n);
    for (auto num : nums) {
        if (freq[num]++ > 0) {
            std::cout << "Yes\n";
            return;
        }
    }

    Fenwick<int> fen(n);
    i64 cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        cnt += fen.sum(nums[i]);
        fen.add(nums[i], 1);
    }

    if (cnt % 2 == 1) {
        std::cout << "No\n";
    } else {
        std::cout << "Yes\n";
    }
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
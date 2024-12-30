// 0725
#include <bits/stdc++.h>

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

    int n, q;
    std::cin >> n >> q;
    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int zero_idx = -1;
    int last_val = 1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            zero_idx = i;
            nums[i] = last_val;;
        } else {
            last_val = nums[i];
        }
    }

    auto max_e = *std::max_element(begin(nums), end(nums));
    if (max_e < q) {
        if (zero_idx != -1) {
            nums[zero_idx] = q;
        } else {
            std::cout << "NO\n";
            return 0;
        }
    } else if (max_e > q) {
        std::cout << "NO\n";
        return 0;
    }

    Fenwick<int> fen(n);
    std::vector<std::vector<int>> positions(q + 1);
    for (int i = 0; i < n; ++i) {
        positions[nums[i]].push_back(i);
    }

    for (int val = 1; val <= q; ++val) {
        auto& pos = positions[val];
        if (size(pos) == 0) {
            continue;
        }

        fen.add(pos[0], 1);
        for (int i = 1; i < size(pos); ++i) {
            int l = pos[i - 1];
            int r = pos[i];
            if (fen.rangeSum(l + 1, r) > 0) {
                std::cout << "NO\n";
                return 0;
            }
            fen.add(r, 1);
        }
    }
    std::cout << "YES\n";
    for (auto num : nums) {
        std::cout << num << " ";
    }

    return 0;
}
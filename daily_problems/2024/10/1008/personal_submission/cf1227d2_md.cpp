// 1008

#include <bits/stdc++.h>

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

    // x = fen.kth_lower_bound(val), sum = fen.sum(x + 1);
    int kth_lower_bound(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i > 0; i >>= 1) {
            if (x + i - 1 < n && k > a[x + i - 1]) {
                k -= a[x + i - 1];
                x += i;
            }
        }
        return x;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> raw_nums(n);
    std::vector<std::pair<int, int>> nums;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        nums.emplace_back(x, i);
        raw_nums[i] = x;
    }

    sort(begin(nums), end(nums), [](auto&& lhs, auto&& rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    });

    int q;
    std::cin >> q;
    std::vector<std::vector<int>> qGroups(n);
    std::vector<int> qPos(q);
    for (int i = 0; i < q; ++i) {
        int k, pos;
        std::cin >> k >> pos;
        qGroups[k - 1].push_back(i);
        qPos[i] = pos;
    }

    Fenwick<int> fen(n);
    std::vector<int> ret(q);
    for (int i = 0; i < n; ++i) {
        fen.add(nums[i].second, 1);

        for (int qid : qGroups[i]) {
            auto pos = qPos[qid];
            auto raw_idx = fen.kth_lower_bound(pos);
            ret[qid] = raw_nums[raw_idx];
        }
    }

    for (auto v : ret) {
        std::cout << v << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{}); 
    }
    
    void add(int x, const T &v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);  
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    Fenwick<int> f(n);
    std::vector<int> a(n + 1);
    std::vector<std::vector<int>> st(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        a[i] = std::min(a[i], n);
        st[a[i]].push_back(i);
    }

    i64 ans = 0;
    for (int i = n; i; i--) {
        for (int x : st[i]) {
            f.add(x, 1);
        }
        if (a[i] > i)
            ans += f.rangeSum(i, a[i]);
    }

    std::cout << ans;

    return 0;
}

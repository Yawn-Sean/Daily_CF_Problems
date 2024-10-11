#include <bits/stdc++.h>
#include <ranges>
// #define DEBUG
using i64 = long long;
using u32 = unsigned;
using u64 = unsigned long long;
constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr double eps = 1e-9;

template<typename T = int>
class FenWick {
private:
    int n;
    std::vector<T> tr;
public:
    FenWick(int _n) : n(_n), tr(_n + 1) 
    {}

    FenWick(const std::vector<T> &_init) : FenWick(_init.size()) {
        init(_init);
    }

    void init(const std::vector<T> &_init) {
        for (int i = 1; i <= n; ++ i) {
            tr[i] += _init[i - 1];
            int j = i + (i & -i);
            if (j <= n)
                tr[j] += tr[i];
        }
    }

    void add(T x, T k) {
        for (; x <= n; x += x & -x) tr[x] += k;
    }

    void add(T l, T r, T k) {
        add(l, k), add(r + 1, -k);
    }

    T query(T x) const {
        T res = T{};
        for (; x; x &= x - 1) res += tr[x];
        return res;
    }

    T query(T l, T r) const {
        if (l > r) return T{};
        return query(r) - query(l - 1);
    }

    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + tr[x + i] <= k) {
                x += i;
                cur = cur + tr[x];
            }
        }
        return x;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::vector<int>> val(n + 1);

    FenWick tr(n);

    for (int i = 0; i < n; ++ i) {
        std::cin >> a[i];
        val[std::min(a[i], n)].push_back(i);
    }

    i64 res = 0;

    for (int i = n - 1; ~i; -- i) {
        for (int x : val[i + 1])
            tr.add(x + 1, 1);

        if (a[i] > i + 1) {
            res += tr.query(i + 2, std::min(a[i], n));
        }
    }

    std::cout << res << '\n';
}

auto FIO = []{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
} ();

int main() {
    #ifdef DEBUG
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif     

    int t = 1;
    // std::cin >> t;
    while (t --)
        solve();

    return 0;
}
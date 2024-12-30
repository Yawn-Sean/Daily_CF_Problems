constexpr int maxn = 2E5 + 10;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    // x处增加v
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = max(a[i - 1], v);
        }
    }
    // [0, x)和
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = max(ans, a[i - 1]);
        }
        return ans;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<pii> f;
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        if (x <= i) {
            f.push_back({i - x, x});
        }
    }
    sort(f.begin(), f.end());

    int k = f.size(), ans = 0;
    Fenwick<int> ft(maxn);
    for (int i = 0; i < k; i++) {
        int len = ft.sum(f[i].second);
        ft.add(f[i].second, len + 1);
        ans = max(ans, len + 1);
    }
    std::cout << ans << '\n';
}
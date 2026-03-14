/**   树状数组（Fenwick 新版）
*    2023-12-28: https://codeforces.com/contest/1915/submission/239262801
**/
template<typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }

    // 前x项前缀和 <= k
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};


void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    i64 res = 0;
    vector<i64> sum(n + 1);

    auto cal_reverse_pairs = [&](vector<i64> arr) -> i64 {
        vector<i64> t = arr;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        int m = t.size();
        Fenwick<i64> fwk(m);
        i64 res = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int j = lower_bound(t.begin(), t.end(), arr[i]) - t.begin();
            res += fwk.sum(j);
            fwk.add(j, 1);
        }
        return res;
    };

    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + 1LL * n * p[i] - (1LL * b * n + 1);
    }
    res += cal_reverse_pairs(sum);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + 1LL * n * p[i] - 1LL * a * n;
    }
    res -= cal_reverse_pairs(sum);
    cout << res;
}

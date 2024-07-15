#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        p++;
        while (p <= _n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    void init() {
        for (int i = 0; i < _n; i ++)
            data[i] = 0;
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<T> data;

    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    
    vector<int> nums(n);
    for (auto &num: nums) cin >> num, num --;

    fenwick_tree<long long> fen(n);
    vector<long long> dp(n, 1);

    for (int _ = 0; _ < k; _ ++) {
        fen.init();
        for (int i = 0; i < n; i ++) {
            fen.add(nums[i], dp[i]);
            dp[i] = fen.sum(0, nums[i]);
        }
    }
    long long ans = 0;
    for (auto &x: dp) ans += x;
    cout << ans;

    return 0;
}
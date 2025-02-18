#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
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

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    stable_sort(order.begin(), order.end(), [&] (int i, int j) {return nums[i] < nums[j];});

    fenwick_tree<int> fen(n);
    vector<int> ans(n);

    for (auto &i: order) {
        for (int k = 1; k < n; k ++) {
            int l = k * i + 1, r = min(k * (i + 1) + 1, n);
            if (l >= n) break;
            ans[k] += fen.sum(l, r);
        }
        fen.add(i, 1);
    }

    for (int i = 1; i < n; i ++) cout << ans[i] << ' ';

    return 0;
}
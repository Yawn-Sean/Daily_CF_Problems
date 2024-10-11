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

    int bisect_min_larger(T x) {
        if (x <= 0) return -1;
        int note = -1;
        T tmp = 0;
        for (int pw = 1 << 32 - __builtin_clz(_n); pw > 0; pw >>= 1) {
            if (note + pw < _n && tmp + data[note + pw] < x) {
                note += pw;
                tmp += data[note];
            }
        }
        return note + 1;
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
    stable_sort(order.begin(), order.end(), [&](int i, int j) {return -nums[i] < -nums[j];});

    vector<int> xs;
    vector<vector<int>> queries(n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i ++) {
        int k, x;
        cin >> k >> x;
        queries[k - 1].emplace_back(i);
        xs.emplace_back(x);
    }

    vector<int> ans(q);

    fenwick_tree<int> fen(n);
    for (int i = 0; i < n; i ++) {
        fen.add(order[i], 1);
        for (auto q_id: queries[i])
            ans[q_id] = nums[fen.bisect_min_larger(xs[q_id])];
    }

    for (auto &v: ans) cout << v << '\n';

    return 0;
}
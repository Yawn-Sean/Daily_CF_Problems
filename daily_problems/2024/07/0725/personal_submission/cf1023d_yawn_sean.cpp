#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
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

    int n, q;
    cin >> n >> q;
    
    vector<int> nums(n);
    for (auto &num: nums) cin >> num;

    int zero_idx = -1, cur = 1, ma = 0;
    for (int i = 0; i < n; i ++) {
        ma = max(ma, nums[i]);
        if (nums[i] == 0)
            nums[i] = cur, zero_idx = i;
        else
            cur = nums[i];
    }

    if (ma < q) {
        if (zero_idx >= 0)
            nums[zero_idx] = q;
        else {
            cout << "NO";
            return 0;
        }
    }

    vector<vector<int>> pos(q + 1);

    for (int i = 0; i < n; i ++)
        pos[nums[i]].emplace_back(i);
    
    fenwick_tree<int> fen(n);
    for (int i = 1; i <= q; i ++) {
        if (pos[i].size()) {
            if (fen.sum(pos[i][0], pos[i].back() + 1)) {
                cout << "NO";
                return 0;
            }
            for (auto &p: pos[i]) fen.add(p, 1);
        }
    }
    cout << "YES\n";
    for (auto &x: nums) cout << x << ' ';

    return 0;
}
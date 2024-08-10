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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &x: nums) cin >> x, x --;

        vector<int> cnt(n);
        bool flg = false;

        for (auto &x: nums) {
            if (cnt[x]) flg = true;
            cnt[x] ++;
        }

        if (!flg) {
            int cnt = 0;
            fenwick_tree<int> fen(n);
            for (int i = n - 1; i >= 0; i --) {
                cnt ^= fen.sum(0, nums[i]) & 1;
                fen.add(nums[i], 1);
            }
            flg = cnt == 0;
        }
        cout << (flg ? "YES\n" : "NO\n");
    }

    return 0;
}
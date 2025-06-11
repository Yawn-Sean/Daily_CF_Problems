#include <bits/stdc++.h>
using namespace std;

template <class T> struct fenwick_tree {
  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        p++;
        while (p <= _n) {
            data[p - 1] += T(x);
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
        
        vector<int> nums(n), vals;
        for (int i = 0; i < n; i ++) 
            cin >> nums[i], vals.push_back(nums[i]);
        
        sort(vals.begin(), vals.end());
        fenwick_tree<int> fen(n);

        long long ans = 0;
        for (auto &x: nums) {
            int p1 = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
            int p2 = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
            ans += min(fen.sum(0, p1), fen.sum(p2, n));
            fen.add(p1, 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
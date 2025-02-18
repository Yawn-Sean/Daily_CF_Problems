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

    int q;
    map<int, vector<array<int, 3>>> mp;

    cin >> q;
    for (int i = 0; i < q; i ++) {
        int a, t, x;
        cin >> a >> t >> x;
        mp[x].push_back({a, t, i});
    }

    vector<int> ans(q, -1);

    for (auto &[k, v]: mp) {
        vector<int> times;
        for (auto &x: v) times.emplace_back(x[1]);
        sort(times.begin(), times.end());

        fenwick_tree<int> fen(times.size());

        for (auto &x: v) {
            int idx = lower_bound(times.begin(), times.end(), x[1]) - times.begin();

            if (x[0] == 1) fen.add(idx, 1);
            else if (x[0] == 2) fen.add(idx, -1);
            else ans[x[2]] = fen.sum(0, idx + 1);
        }
    }

    for (auto &v: ans)
        if (v != -1)
            cout << v << '\n';

    return 0;
}
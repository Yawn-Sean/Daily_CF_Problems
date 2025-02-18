#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

struct unionfind {
  public:
    unionfind() : _n(0) {}
    explicit unionfind(int n) : _n(n), parent_or_size(n, -1) {}

    bool merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> xs(n), ys(n);
    map<int, int> mp_x, mp_y;
    for (int i = 0; i < n; i ++)
        cin >> xs[i] >> ys[i], mp_x[xs[i]] ++, mp_y[ys[i]] ++;
    
    int cur = 0;
    for (auto &[k, v]: mp_x)
        mp_x[k] = cur ++;
    
    for (auto &[k, v]: mp_y)
        mp_y[k] = cur ++;
    
    vector<int> edge_cnt(cur, 0);
    unionfind dsu(cur);

    for (int i = 0; i < n; i ++)
        dsu.merge(mp_x[xs[i]], mp_y[ys[i]]);
    
    for (int i = 0; i < n; i ++)
        edge_cnt[dsu.leader(mp_x[xs[i]])] ++;
    
    int ans = 1, mod = 1e9 + 7;
    for (int i = 0; i < cur; i ++) {
        if (edge_cnt[i]) {
            int c = dsu.size(i);
            ans = (edge_cnt[i] >= c ? quickPow(2, c, mod) : quickPow(2, c, mod) - 1) * ans % mod;
        }
    }
    cout << ans << '\n';

    return 0;
}
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

    void reset(int x) {
        parent_or_size[x] = -1;
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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> nums(n);
    for (auto &v: nums) cin >> v;

    map<long long, vector<int>> mp;
    vector<int> us, vs;

    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        u --, v --;
        us.emplace_back(u);
        vs.emplace_back(v);
        mp[nums[u] ^ nums[v]].emplace_back(i);
    }

    int mod = 1e9 + 7;
    vector<int> pow2(n + 1, 1);

    for (int i = 0; i < n; i ++)
        pow2[i + 1] = pow2[i] * 2 % mod;
    
    int ans = ((1ll << k) - mp.size()) % mod * pow2[n] % mod;
    unionfind dsu(n);

    for (auto &[k, x]: mp) {
        int cur = n;
        for (auto &i: x)
            if (dsu.merge(us[i], vs[i]))
                cur --;
        ans += pow2[cur];
        if (ans >= mod) ans -= mod;
        for (auto &i: x)
            dsu.reset(us[i]), dsu.reset(vs[i]);
    }
    cout << ans;

    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

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

    void init() {
        for (auto &x: parent_or_size) x = -1;
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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    dsu unions(n);

    vector<int> us(m), vs(m), ls(m), rs(m);
    vector<int> tmpl(m), tmpr(m);

    for (int i = 0; i < m; i ++) {
        cin >> us[i] >> vs[i] >> ls[i] >> rs[i];
        us[i] --, vs[i] --;
        tmpl[i] = ls[i], tmpr[i] = rs[i];
    }

    sort(tmpl.begin(), tmpl.end());
    auto ptl = unique(tmpl.begin(), tmpl.end());
    sort(tmpr.begin(), tmpr.end());
    auto ptr = unique(tmpr.begin(), tmpr.end());

    auto pl = tmpl.begin(), pr = tmpr.begin();
    int ans = 0;

    function<bool(void)> check = [&]() {
        unions.init();
        for (int i = 0; i < m; i ++)
            if (ls[i] <= *pl && rs[i] >= *pr)
                unions.merge(us[i], vs[i]);
        return unions.leader(0) == unions.leader(n - 1);
    };

    while (pl != ptl) {
        while (pr != ptr && check()) pr ++;
        if (pr != tmpr.begin())
            ans = max(ans, *(pr - 1) - *pl + 1);
        pl ++;
    }
    
    if (ans) cout << ans;
    else cout << "Nice work, Dima!";

    return 0;
}
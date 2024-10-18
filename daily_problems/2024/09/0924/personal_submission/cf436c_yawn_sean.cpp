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

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k, w;
    cin >> n >> m >> k >> w;

    vector<vector<string>> grids(k, vector<string>(n));

    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> grids[i][j];
        }
    }

    vector<int> us, vs, ws;

    for (int i = 0; i < k; i ++) {
        us.emplace_back(i);
        vs.emplace_back(k);
        ws.emplace_back(n * m);

        for (int j = 0; j < i; j ++) {
            int cost = 0;

            for (int x = 0; x < n; x ++) {
                for (int y = 0; y < m; y ++) {
                    if (grids[i][x][y] != grids[j][x][y])
                        cost += w;
                }
            }

            us.emplace_back(i);
            vs.emplace_back(j);
            ws.emplace_back(cost);
        }
    }

    int e = ws.size();
    vector<int> es(e);

    iota(es.begin(), es.end(), 0);
    sort(es.begin(), es.end(), [&](int i, int j) {return ws[i] < ws[j];});

    unionfind dsu(k + 1);
    int ans = 0;
    vector<vector<int>> path(k + 1);

    for (auto &i: es) {
        if (dsu.merge(us[i], vs[i])) {
            ans += ws[i];
            path[us[i]].emplace_back(vs[i]);
            path[vs[i]].emplace_back(us[i]);
        }
    }

    cout << ans << '\n';

    vector<pair<int, int>> stk;
    stk.emplace_back(k, -1);

    while (!stk.empty()) {
        auto [u, p] = stk.back();
        stk.pop_back();

        for (auto v: path[u]) {
            if (v != p) {
                cout << v + 1 << ' ' << (u < k ? u + 1 : 0) << '\n';
                stk.emplace_back(v, u);
            }
        }
    }

    return 0;
}
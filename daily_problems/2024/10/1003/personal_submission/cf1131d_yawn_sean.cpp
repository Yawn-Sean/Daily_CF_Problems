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

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &s: grid) cin >> s;

    unionfind dsu(n + m);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (grid[i][j] == '=') {
                dsu.merge(i, n + j);
            }
        }
    }

    vector<vector<int>> path(n + m);
    vector<int> indegs(n + m, 0);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int u = dsu.leader(i), v = dsu.leader(n + j);
            if (grid[i][j] == '<')  {
                path[u].emplace_back(v);
                indegs[v] ++;
            }
            else if (grid[i][j] == '>') {
                path[v].emplace_back(u);
                indegs[u] ++;
            }
        }
    }

    vector<int> stk, ans(n + m, 0);
    for (int i = 0; i < n + m; i ++) {
        if (indegs[i] == 0) {
            stk.emplace_back(i);
            ans[i] = 1;
        }
    }

    int cnt = 0;
    while (!stk.empty()) {
        int u = stk.back();
        stk.pop_back();
        cnt ++;
        for (auto &v: path[u]) {
            ans[v] = max(ans[v], ans[u] + 1);
            indegs[v] --;
            if (indegs[v] == 0) stk.emplace_back(v);
        }
    }

    if (cnt < n + m) cout << "No";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; i ++) cout << ans[dsu.leader(i)] << ' ';
        cout << '\n';
        for (int i = 0; i < m; i ++) cout << ans[dsu.leader(n + i)] << ' ';
    }

    return 0;
}
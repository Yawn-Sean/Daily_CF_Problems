#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
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
    long long k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));

    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> grid[i][j], tmp.emplace_back(i, j);
    
    unionfind dsu(n * m);

    sort(tmp.begin(), tmp.end(), [&] (pair<int, int> x, pair<int, int> y) {return grid[x.first][x.second] > grid[y.first][y.second];});

    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (auto &[x, y]: tmp) {
        for (auto &[dx, dy]: dirs) {
            if (0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < m && grid[x + dx][y + dy] >= grid[x][y])
                dsu.merge(x * m + y, (x + dx) * m + y + dy);
        }
        if (k % grid[x][y] == 0 && dsu.size(x * m + y) >= k / grid[x][y]) {
            cout << "YES\n";
            vector<vector<int>> ans(n, vector<int>(m, 0));
            int v = grid[x][y], cnt = k / grid[x][y];
            
            auto dfs = [&] (auto &self, int x, int y) {
                if (cnt == 0) return ;
                ans[x][y] = v, cnt --;

                for (auto &[dx, dy]: dirs) {
                    if (0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < m && grid[x + dx][y + dy] >= v && ans[x + dx][y + dy] == 0)
                        self(self, x + dx, y + dy);
                }
            };

            dfs(dfs, x, y);

            for (auto &v: ans) {
                for (auto &x: v) cout << x << ' ';
                cout << '\n';
            }
            return 0;
        }
    }
    cout << "NO";

    return 0;
}
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/convolution"
// #include "atcoder/dsu"
// #include "atcoder/fenwicktree"
// #include "atcoder/lazysegtree"
// #include "atcoder/math"
// #include "atcoder/maxflow"
// #include "atcoder/mincostflow"
// #include "atcoder/modint"
// #include "atcoder/scc"
// #include "atcoder/segtree"
// #include "atcoder/string"
// #include "atcoder/twosat"
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divide, I conquer!
char *p1, *p2, buf[100000];
#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
int read()
{
    int x = 0;
	int f = 1;
    char ch = nc();
    while (ch < 48 || ch > 57)
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= 48 && ch <= 57)
        x = x * 10 + ch - 48, ch = nc();
   	return x * f;
}

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

    void init() {
        for (int i = 0; i < _n; i ++)
            parent_or_size[i] = -1;
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

struct unionfind1 {
  public:
    unionfind1() : _n(0) {}
    explicit unionfind1(int n) : _n(n), parent_or_size(n, -1) {}

    bool merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return true;
    }

    void init() {
        for (int i = 0; i < _n; i ++)
            parent_or_size[i] = -1;
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = read(), m = read(), q = read();

    auto f = [&] (int i, int j) -> int {
        return i * m + j;
    };

    vector<int> grid(n * m);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            grid[f(i, j)] = read() - 1;
        }
    }

    vector<int> pos, cols;

    for (int i = 0; i < q; i ++) {
        int x = read() - 1, y = read() - 1, c = read() - 1;
        pos.emplace_back(x * m + y);
        cols.emplace_back(c);
    }

    vector<vector<long long>> pos_op(n * m);

    for (int i = 0; i < n * m; i ++)
        pos_op[grid[i]].emplace_back(1ll * i * (q + 2));

    vector<int> vis(n * m, 0);

    for (int i = 0; i < q; i ++) {
        int p = pos[i], c = cols[i];
        if (!vis[p]) {
            if (grid[p] != c) {
                pos_op[grid[p]].emplace_back(~(1ll * p * (q + 2) + i + 1));
                pos_op[c].emplace_back(1ll * p * (q + 2) + i + 1);
            }
            vis[p] = 1;
        }
    }

    for (int i = 0; i < n * m; i ++)
        vis[i] = -1;
    
    vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vector<int> ans(q + 1, 0), state(n * m, 0);
    vector<vector<long long>> updates(n * m + 1);

    auto apply = [&] (int i, int j, int x) -> void {
        updates[x].emplace_back(1ll * i * (q + 2) + j);
    };

    for (int i = 0; i < n * m; i ++) {
        vector<int> chosen;

        for (auto &op: pos_op[i]) {
            int p;
            if (op >= 0) p = op / (q + 2);
            else p = (~op) / (q + 2);

            if (vis[p] == -1) {
                vis[p] = chosen.size();
                chosen.emplace_back(p);
            }
        }

        int l = chosen.size(), k = pos_op[i].size();
        unionfind dsu(l);

        for (int j = 0; j <= k; j ++) {
            if ((j == 0 || pos_op[i][j - 1] < 0) && (j == k || pos_op[i][j] >= 0)) {
                int cur_ans = 0, tmp_ans, tmstamp, ntmstamp;
                dsu.init();

                for (int idx = 0; idx < l; idx ++) {
                    if (state[chosen[idx]]) {
                        if (cur_ans == 0) cur_ans = 1;
                        int p = chosen[idx];
                        int x = p / m, y = p % m;
                        for (auto &[dx, dy]: dirs) {
                            int nx = x + dx;
                            int ny = y + dy;
                            int np = nx * m + ny;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && state[np])
                                dsu.merge(vis[p], vis[np]);
                        }
                        cur_ans = max(cur_ans, dsu.size(idx));
                    }
                }

                tmp_ans = cur_ans;
                tmstamp = j < k ? pos_op[i][j] % (q + 2) : q + 1;

                for (int idx = j - 1; idx >= 0; idx --) {
                    if (pos_op[i][idx] >= 0) break;
                    int p = (~pos_op[i][idx]) / (q + 2);
                    ntmstamp = (~pos_op[i][idx]) % (q + 2);
                    state[p] = 1;
                    int x = p / m, y = p % m;
                    for (auto &[dx, dy]: dirs) {
                        int nx = x + dx;
                        int ny = y + dy;
                        int np = nx * m + ny;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && state[np])
                            dsu.merge(vis[p], vis[np]);
                    }
                    if (ntmstamp < tmstamp) {
                        apply(ntmstamp, tmstamp, tmp_ans);
                        tmstamp = ntmstamp;
                    }
                    tmp_ans = max(tmp_ans, dsu.size(vis[p]));
                }
                for (int idx = j - 1; idx >= 0; idx --) {
                    if (pos_op[i][idx] >= 0) break;
                    state[(~pos_op[i][idx]) / (q + 2)] = 0;
                }
                if (j > 0) {
                    dsu.init();
                    for (int idx = 0; idx < l; idx ++) {
                        int p = chosen[idx];
                        if (state[p]) {
                            int x = p / m, y = p % m;
                            for (auto &[dx, dy]: dirs) {
                                int nx = x + dx;
                                int ny = y + dy;
                                int np = nx * m + ny;
                                if (nx >= 0 && nx < n && ny >= 0 && ny < m && state[np])
                                    dsu.merge(vis[p], vis[np]);
                            }
                        }
                    }
                }
                if (j < k) {
                    tmp_ans = cur_ans;
                    tmstamp = j < k ? pos_op[i][j] % (q + 2) : q + 1;
                    bool flg = true;
                    for (int idx = j; idx < k; idx ++) {
                        if (pos_op[i][idx] < 0) {
                            flg = false;
                            break;
                        }
                        int p = pos_op[i][idx] / (q + 2);
                        state[p] = 1;
                        int x = p / m, y = p % m;
                        for (auto &[dx, dy]: dirs) {
                            int nx = x + dx;
                            int ny = y + dy;
                            int np = nx * m + ny;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < m && state[np])
                                dsu.merge(vis[p], vis[np]);
                        }

                        if (idx == k - 1) ntmstamp = q + 1;
                        else if (pos_op[i][idx + 1] >= 0) ntmstamp = pos_op[i][idx + 1] % (q + 2);
                        else ntmstamp = (~pos_op[i][idx + 1]) % (q + 2);

                        tmp_ans = max(tmp_ans, dsu.size(vis[p]));
                        if (tmstamp < ntmstamp) {
                            apply(tmstamp, ntmstamp, tmp_ans);
                            tmstamp = ntmstamp;
                        }
                    }

                    if (flg) {
                        ntmstamp = q + 1;
                        if (tmstamp < ntmstamp)
                            apply(tmstamp, ntmstamp, tmp_ans);
                    }

                    for (int idx = j; idx < k; idx ++) {
                        if (pos_op[i][idx] < 0) break;
                        state[pos_op[i][idx] / (q + 2)] = 0;
                    }
                }
            }

            if (j < k) {
                if (pos_op[i][j] >= 0) state[pos_op[i][j] / (q + 2)] = 1;
                else state[(~pos_op[i][j]) / (q + 2)] = 0;
            }
        }
        for (auto &x: chosen) {
            state[x] = 0;
            vis[x] = -1;
        }
    }

    unionfind1 dsu1(q + 3);

    for (int i = n * m; i >= 1; i --) {
        for (auto &v: updates[i]) {
            int l = v / (q + 2), r = v % (q + 2);
            while (true) {
                l = dsu1.leader(l);
                if (l >= r) break;
                ans[l] = i;
                dsu1.merge(l + 1, l);
            }
        }
    }

    for (auto &x: ans) cout << x << '\n';

    return 0;
}
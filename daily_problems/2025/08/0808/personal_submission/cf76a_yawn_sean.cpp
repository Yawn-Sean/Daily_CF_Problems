#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

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

    bool merge_to(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return false;
        parent_or_size[y] += parent_or_size[x];
        parent_or_size[x] = y;
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
    std::vector<int> parent_or_size;
};

}  // namespace atcoder


using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, g, s;
    cin >> n >> m >> g >> s;

    vector<array<int, 4>> edges(m);

    for (auto &x: edges) {
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        x[0] --, x[1] --;
    }

    sort(edges.begin(), edges.end(), [&] (array<int, 4> x, array<int, 4> y) {return x[2] < y[2];});

    atcoder::dsu uf(n);

    vector<int> cur_edges;
    long long inf = 3e18, ans = inf;

    for (int i = 0; i < m; i ++) {
        cur_edges.emplace_back(i);

        for (int j = cur_edges.size() - 1; j > 0; j --) {
            if (edges[cur_edges[j]][3] < edges[cur_edges[j - 1]][3]) {
                swap(cur_edges[j], cur_edges[j - 1]);
            }
        }

        uf.init();

        vector<int> new_edges;
        int cs = 0, cnt = n;

        for (auto &eid: cur_edges) {
            if (uf.merge(edges[eid][0], edges[eid][1])) {
                cs = edges[eid][3], cnt --, new_edges.emplace_back(eid);
            }
        }

        if (cnt == 1) ans = min(ans, 1ll * edges[i][2] * g + 1ll * cs * s);
        cur_edges.swap(new_edges);
    }

    cout << (ans < inf ? ans : -1);

    return 0;
}
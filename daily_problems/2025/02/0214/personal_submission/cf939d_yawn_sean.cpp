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
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s1, s2;

    cin >> n >> s1 >> s2;

    unionfind uf(26);
    vector<pair<char, char>> ans;

    for (int i = 0; i < n; i ++) {
        if (uf.merge(s1[i] - 'a', s2[i] - 'a')) {
            ans.emplace_back(s1[i], s2[i]);
        }
    }

    cout << ans.size() << '\n';
    for (auto &[x, y]: ans)
        cout << x << ' ' << y << '\n';

    return 0;
}
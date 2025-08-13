#include <algorithm>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;
using std::min;
using std::queue;
using std::string;
using std::vector;
using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> path(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    path[u].push_back(v);
    path[v].push_back(u);
  }
  int w;
  cin >> w;
  vector<int> cs(w), ks(w), ps(w);
  for (int i = 0; i < w; i++) {
    cin >> cs[i] >> ks[i] >> ps[i];
    --cs[i];
  }

  vector<int> order(w);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) { return ps[i] < ps[j]; });
  int Q;
  cin >> Q;
  while (Q--) {
    int g, r;
    i64 a;
    cin >> g >> r >> a;
    --g;
    vector<int> dis(n, n);
    dis[g] = 0;
    queue<int> q;
    q.push(g);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : path[u]) {
        if (dis[v] > dis[u] + 1) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
      }
    }

    auto check = [&](int mid) {
      int cur_left = r;
      i64 cost = 0;
      for (auto& idx : order) {
        if (cur_left <= 0) {
          break;
        }
        if (dis[cs[idx]] <= mid) {
          int buy = min(cur_left, ks[idx]);
          cost += 1ll * buy * ps[idx];
          cur_left -= buy;
        }
      }
      return cur_left == 0 && cost <= a;
    };

    int ans = n + 1;
    int left = 0, right = n;
    while (left < right) {
      int mid = (left + right) / 2;
      if (!check(mid)) {
        left = mid + 1;
      } else {
        right = mid;
        ans = mid;
      }
    }
    cout << ((ans >= n) ? -1 : ans) << endl;
  }
  return 0;
}

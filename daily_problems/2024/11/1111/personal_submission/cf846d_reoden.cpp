#include <bits/stdc++.h>

template <typename T> struct pref_sum_2d {
  int n, m;
  std::vector<std::vector<T>> sum;
  template <typename U>
  pref_sum_2d(const std::vector<std::vector<U>> &a)
      : n((int)a.size()), m((int)a[0].size()), sum(n + 1, std::vector<T>(m + 1)) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        sum[i + 1][j + 1] = a[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
      }
  }
  T query(int x1, int y1, int x2, int y2) {
    return sum[x2 + 1][y2 + 1] - sum[x2 + 1][y1] - sum[x1][y2 + 1] + sum[x1][y1];
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N, M, K, Q; std::cin >> N >> M >> K >> Q;
  std::vector timestamps(N, std::vector<int>(M, -1));

  int lo = 0, hi = 0;
  for (int i = 0; i < Q; i++) {
    int x, y, t;
    std::cin >> x >> y >> t;
    x--, y--;
    timestamps[x][y] = t;
    hi = std::max(hi, t);
  }

  int ans = -1;

  auto check = [&](int m) -> bool {
    auto now = timestamps;
    for (auto &row : now) for (auto &x : row) x = (x >= 0 && x <= m);
    // DEBUG << KV(m) << ' ' << KV(now) << '\n';
    auto psum = pref_sum_2d<int>(now);
    for (int i = 0; i+K <= N; i++) {
      for (int j = 0; j+K <= M; j++) {
        // std::cerr << i << ' ' << j << ' ' << i + K << ' ' << j + K << ' ' << psum.query(i, j, i+K-1, j+K-1) << '\n';
        if (psum.query(i, j, i+K-1, j+K-1) == K * K) {
          return true;
        }
      }
    }
    return false;
  };

  while (lo <= hi) {
    int m = (lo + hi) / 2;
    std::cerr << lo << ' ' << hi << ' ' << m << '\n';
    if (check(m)) {
      hi = m - 1;
      ans = m;
    } else {
      lo = m + 1;
    }
  }

  std::cout << ans << '\n';
}

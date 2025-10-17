#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct BIT {
  int n;
  vector<int> t;
  void init(int n_) {
    n = n_;
    t.assign(n + 1, 0);
  }
  void add(int idx, int delta) {
    for (idx++; idx <= n; idx += idx & -idx) t[idx] += delta;
  }
  int sumPrefix(int idx) {
    int s = 0;
    for (idx++; idx > 0; idx -= idx & -idx) s += t[idx];
    return s;
  }
  int rangeSum(int l, int r) {
    if (l > r) return 0;
    if (l < 0) l = 0;
    if (r >= n) r = n - 1;
    if (l > r) return 0;
    return sumPrefix(r) - sumPrefix(l - 1);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<int>> L(n, vector<int>(n, 0));
  vector<vector<int>> R(n, vector<int>(n, 0));
  vector<vector<int>> U(n, vector<int>(n, 0));
  vector<vector<int>> D(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j]) {
        L[i][j] = (j ? L[i][j - 1] : 0) + 1;
        U[i][j] = (i ? U[i - 1][j] : 0) + 1;
      }
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (grid[i][j]) {
        R[i][j] = (j + 1 < n ? R[i][j + 1] : 0) + 1;
        D[i][j] = (i + 1 < n ? D[i + 1][j] : 0) + 1;
      }
    }
  }

  auto process_diag = [&](int si, int sj) -> i64 {
    int len = min(n - si, n - sj);
    if (len <= 0) return 0;
    BIT bit;
    bit.init(len);
    using P = pair<int, int>;  // (T, p)
    priority_queue<P, vector<P>, greater<P>> pq;

    i64 cnt = 0;
    for (int k = 0; k < len; k++) {
      int i = si + k, j = sj + k;

      int g = min(R[i][j], D[i][j]);
      int T = g + k - 1;
      bit.add(k, 1);
      pq.emplace(T, k); // 理论上 最远能够覆盖到的右下角

      // 此时有效的右下角区域
      while (!pq.empty() && pq.top().first < k) {
        bit.add(pq.top().second, -1);
        pq.pop();
      }

      // 右下角为(i, j) 左上角的范围 [LB, k]
      int b = min(L[i][j], U[i][j]);
      int LB = k - b + 1;
      if (LB < 0) {
        LB = 0;
      }

      if (LB <= k) {
        cnt += bit.rangeSum(LB, k);
      }
    }

    return cnt;
  };

  i64 ans = 0;
  for (int i = 0; i < n; i++) {
    ans += process_diag(i, 0);
  }
  for (int j = 1; j < n; j++) {
    ans += process_diag(0, j);
  }
  cout << ans << "\n";
  return 0;
}

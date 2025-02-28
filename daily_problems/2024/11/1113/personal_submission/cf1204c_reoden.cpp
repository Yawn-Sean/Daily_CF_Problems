#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N; std::cin >> N;
  constexpr int inf = std::numeric_limits<int>::max() / 2;

  ten dp({N, N});
  for (auto &&i : std::views::iota(0, N)) {
    std::string S;
    std::cin >> S;
    // std::cerr << S << '\n';
    for (auto &&j : std::views::iota(0, N)) {
      if (S[j] & 1) {
        dp[{i, j}] = 1;
      } else {
        dp[{i, j}] = inf;
      }
    }
  }

  for (auto &&i : std::views::iota(0, N)) dp[{i, i}] = 0;

  int M;
  std::cin >> M;
  std::vector<int> path(M);
  for (auto &x : path) std::cin >> x, x--;

  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[{i, j}] = std::min(dp[{i, j}], dp[{i, k}] + dp[{k, j}]);
      }
    }
  }

  int last = 0;
  int u = path.front();
  std::vector<int> ans{u};

  for (auto &&i : std::views::iota(1, M)) {
    if (dp[{u, path[i]}] < i - last) {
      u = path[i-1];
      ans.push_back(path[i-1]);
      last = i-1;
    } 
  }

  ans.push_back(path.back());
  std::cout << ans.size() << '\n';
  for (size_t i = 0; i < ans.size(); i++) std::cout << ans[i]+1 << " \n"[i+1 == ans.size()];
}

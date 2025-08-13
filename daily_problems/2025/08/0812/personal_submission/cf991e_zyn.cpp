#include <bits/stdc++.h>

using i64 = long long;

constexpr int MAXN = 20;
i64 C[MAXN][MAXN];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  for (int i = *C[0] = 1; i < 20; ++i) {
    for (int j = *C[i] = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  std::vector <i64> dp(20, 0);
  auto empty = dp;
  std::string A;
  std::cin >> A;

  std::vector <int> buk(10, 0);
  for (char a : A) {
    ++buk[a - '0'];
  }

  int N = A.length();
  dp[0] = 1;
  for (int i = 1; i < 10; ++i) {
    auto ndp = empty;
    for (int j = 0; j <= N; ++j) {
      if (!dp[j]) continue;
      for (int k = std::min(1, buk[i]); k <= buk[i]; ++k) {
        ndp[j + k] += dp[j] * C[j + k][j];
        // printf("%d => %d %d\n", i, j, k);
      }
    }

    dp = ndp;
  }

  i64 ans = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = std::min(1, buk[0]); j <= buk[0]; ++j) {
      ans += dp[i] * C[i + j - 1][j];
    }
  }

  std::cout << ans << '\n';

  return 0;
}
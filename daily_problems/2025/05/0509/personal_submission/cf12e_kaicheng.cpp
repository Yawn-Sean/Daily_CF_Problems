#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));

  for (int i = 1; i <= n - 1; ++i) {
    int k = i;
    for (int j = 1; j <= n - 1; ++j) {
      a[j][i] = k;
      k++;
      if (k == n)
        k = 1;
    }
  }

  for (int i = 1; i <= n; ++i) {
    a[i][n] = a[n][i] = a[i][i];
    a[i][i] = 0;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cout << a[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
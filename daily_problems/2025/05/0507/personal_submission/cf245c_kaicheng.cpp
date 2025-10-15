#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using i128 = __int128;
using u128 = unsigned __int128;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }

  if (n <= 2 || n % 2 == 0) {
    std::cout << -1 << '\n';
    return 0;
  }

  auto f = [](int x) -> int { return (x % 2) ? (x - 1) : (x + 1); };

  int ans = 0;
  for (int i = n; i >= 1; --i) {
    if (a[i] <= 0)
      continue;

    if (f(i) <= n) {
      a[f(i)] -= a[i];
    }

    if (i / 2 >= 1) {
      a[i / 2] -= a[i];
    }

    ans += a[i];
    a[i] = 0;
  }

  std::cout << ans << '\n';

  return 0;
}
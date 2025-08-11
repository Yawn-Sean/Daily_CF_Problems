#include <bits/stdc++.h>

using i64 = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int N, M;
  std::cin >> N >> M;
  std::vector <int> A(N + 1, 0), pos(N + 1, 0), max(N + 1, 0);
  for (int i = 1; i <= N; ++i) {
    std::cin >> A[i];
    pos[A[i]] = i;
  }

  i64 ans = 0;
  for (int i = 1, l, r; i <= M; ++i) {
    std::cin >> l >> r;
    if (pos[l] > pos[r]) std::swap(l, r);
    max[pos[r]] = std::max(max[pos[r]], pos[l] + 1);
  }

  for (int i = 1, pre = 1; i <= N; ++i) {
    pre = std::max(pre, max[i]);
    ans += i - pre + 1;
  }

  std::cout << ans << '\n';

  return 0;
}
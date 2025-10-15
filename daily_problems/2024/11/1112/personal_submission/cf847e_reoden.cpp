#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N; std::string S;
  std::cin >> N >> S;

  int lo = 0, hi = N * 2;
  int ans = -1;

  std::vector<int> packmans, asterisks;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'P') packmans.push_back(i);
    else if (S[i] == '*') asterisks.push_back(i);
  }

  auto check = [&](int m) -> bool {
    int ptr = 0;
    for (auto &loc : packmans) {
      if (std::abs(asterisks[ptr] - loc) > m) continue;
      int l = std::max(0, loc - asterisks[ptr]);
      int r = loc + std::max(m - l * 2, (m - l) / 2);
      while (ptr < static_cast<int>(asterisks.size()) && r >= asterisks[ptr]) ptr++;
      if (ptr == static_cast<int>(asterisks.size())) return true;
    }

    return false;
  };

  while (lo <= hi) {
    int m = (lo + hi) / 2;
    if (check(m)) {
      hi = m - 1;
      ans = m;
    } else {
      lo = m + 1;
    }
  }

  std::cout << ans << '\n';
}

#include <cassert>
#include <iostream>
#include <vector>
#include "modnum.hpp"

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  using num = modnum<1'000'000'007>;

  int N, Q;
  std::cin >> N >> Q;
  std::vector<int> psum(N+1);
  std::string S;
  std::cin >> S;
  for (int i = 0; i < N; i++) {
    psum[i+1] = psum[i] + (S[i] % 2);
  }

  // 000111000
  // cnt_1 = 3, cnt_0 = 6
  // 1 1 1
  // _ 2 2
  // _ _ 4
  // 1 + 2 + 4 = 2 ** 3 - 1
  // 2 ** (cnt_1) - 1 = x
  // x x x x x x
  // x + x(1 + 2 + 4 + 8 + 16 + 32)
  // x * (1 + (1-2 ** 6) / (1-2))
  // x * (1 + (2 ** cnt_0 - 1))
  // (2 ** cnt_1 - 1) * 2 ** cnt_0
  while (Q--) {
    int l, r;
    std::cin >> l >> r;
    l--;
    int cnt1 = psum[r] - psum[l];
    int cnt0 = r-l-cnt1;
    num ans = pow(num(2), cnt0) * (pow(num(2), cnt1) - 1);
    std::cout << ans << '\n';
  }
}

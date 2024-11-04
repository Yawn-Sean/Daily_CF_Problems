#include <cstdint>
#include <iostream>
#include <vector>

#define KV(x) #x << " -> " << x

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N;
  std::cin >> N;
  std::vector<int> A(N), B(N);
  for (auto &a : A) std::cin >> a;
  for (auto &b : B) std::cin >> b;

  auto gao = [&](const std::vector<int> &a) -> std::vector<int64_t> {
    std::vector<int64_t> psum(N + 1);
    for (int i = 0; i < N; i++) {
      psum[i + 1] = psum[i] + a[i];
    }

    return psum;
  };

  auto gv = [&](const std::vector<int> &a) -> std::vector<int64_t> {
    std::vector<int64_t> psum(N + 1);
    for (int i = 0; i < N; i++) {
      psum[i + 1] = psum[i] + 1LL * (i + 1) * a[i];
    }

    return psum;
  };

  auto psuma = gao(A);
  auto psumai = gv(A);
  auto psumb = gao(B);
  auto psumbi = gv(B);

  int64_t ans = 0;
  int64_t t = 0;

  int64_t cur = 0;
  int64_t now = 0;
  for (int i = 0, j = 0; i < N; i++, j ^= 1) {
    std::swap(cur, now);
    int64_t ret = 0;
    if (j & 1) {
      if (i == 0) {
        continue;
      }
      ret = now;
      ret += (t - i - 1) * (psumb[N] - psumb[i]) + psumbi[N] - psumbi[i];
      ret += (t + 2LL * N - i) * (psuma[N] - psuma[i]) - (psumai[N] - psumai[i]);
      //				std::cerr << KV(j) << ' ' << KV(i) << ' ' << KV(t) << ' ' << KV(ret) << ' ' << KV(ans) << '\n';
      ans = std::max(ans, ret);
      now += t * B[i] + (t + 1) * A[i];
    } else {
      ret = cur;
      ret += (t - i - 1) * (psuma[N] - psuma[i]) + psumai[N] - psumai[i];
      ret += (t + 2LL * N - i) * (psumb[N] - psumb[i]) - (psumbi[N] - psumbi[i]);
      //				std::cerr << KV(j) << ' ' << KV(i) << ' ' << KV(t) << ' ' << KV(ret) << ' ' << KV(ans) << '\n';
      ans = std::max(ans, ret);
      cur += t * A[i] + (t + 1) * B[i];
    }
    t += 2;
  }

  std::cout << ans << '\n';
}

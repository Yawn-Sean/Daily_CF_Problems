#include <bits/stdc++.h>

using i64 = long long;

int main() {
  // std::ios::sync_with_stdio(false);
  // std::cin.tie(nullptr);
  // std::cout.tie(nullptr);

  int N;
  std::cin >> N;
  std::vector <int> A(N + 1, 0), B(N + 1, 0);
  bool ok = true;
  for (int i = 1, u, v; i < N; ++i) {
    std::cin >> u >> v;
    ok &= v == N;
    ++A[u], ++B[u];
  }

  for (int i = 1; i < N; ++i) {
    B[i] += B[i - 1];
    ok &= B[i] <= i;
  }

  if (!ok) {
    return puts("NO") & 0;
  }

  auto link = [&](int a, int b) {
    std::cout << a << " " << b << '\n'; 
  };

  std::cout << "YES\n";
  int pre = 0;
  std::vector <int> vis(N + 1, 0);
  for (int i = 1, now = 0; i < N; ++i) {
    if (A[i]) {
      --A[i];
      if (pre) {
        link(pre, i);
      } 

      pre = i;
      vis[i] = 1;
      while (A[i]) {
        ++now;
        while (vis[now]) ++now;
        link(pre, now);
        pre = now;
        --A[i];
      }
    }
  }

  link(pre, N);

  return 0;
}
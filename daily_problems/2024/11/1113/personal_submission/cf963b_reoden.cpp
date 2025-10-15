#include <bits/stdc++.h>

#include <functional>

namespace y_combinator_details {

template <class Fun> struct y_combinator_result {
  template <class T>
  explicit y_combinator_result(T &&fun_) : fun(std::forward<T>(fun_)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun(std::ref(*this), std::forward<Args>(args)...);
  }

private:
  Fun fun;
};

} // namespace y_combinator_details

template <class Fun> static inline decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_details::y_combinator_result<std::decay_t<Fun>>(
      std::forward<Fun>(fun));
}

#define ALL(v) (v).begin(), (v).end()

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int N; std::cin >> N;
  std::vector adj(N, std::vector<int>());

  std::vector<int> deg(N);
  int S = 0;
  for (auto &&i : std::views::iota(0, N)) {
    int p;
    std::cin >> p;
    p--;
    if (p >= 0) {
      adj[p].push_back(i);
      deg[p]++;
      deg[i]++;
    } else {
      S = i;
    }
  }

  if (N % 2 == 0) {
    std::cout << "NO" << '\n';
    return 0;
  }

  std::cout << "YES" << '\n';
  std::vector<int> ans;
  std::vector<char> vis(N);

  y_combinator([&](auto &&dfs, int u, int par) -> void {
    for (auto &v : adj[u]) {
      dfs(v, u);
    }

    if (deg[u] % 2 == 0) {
      if (~par) {
        deg[par]--;
      }

      y_combinator([&](auto &&gao, int u) -> void {
        ans.push_back(u);
        vis[u] = true;
        for (auto &v : adj[u]) {
          if (vis[v] == true) continue;
          gao(v);
        }
      })(u);
    }
  })(S, -1);

  for (auto &x : ans) std::cout << x+1 << '\n';
}

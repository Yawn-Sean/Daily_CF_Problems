int main() {
  std::basic_ostream<char>::sync_with_stdio(false);
  int N, M, S, T;
  std::cin >> N >> M >> S >> T;
  S--;
  T--;

  std::vector<std::vector<int>> adj(N);
  for (auto _ : std::ranges::iota_view{0, M}) {
    int u, v;
    std::cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  std::vector<std::array<int, 2>> Q{{S, 0}};
  std::vector dist(N, -1);

  dist[S] = 0;
  using num = modnum<1'000'000'007>;
  std::vector dp(N, std::array<num, 2>());
  dp[S][0] = 1;

  std::vector<char> vis(N);

  while (!Q.empty()) {
    std::vector<std::array<int, 2>> cur;
    for (auto &q : Q) {
      const int u = q[0];
      const int ext = q[1];
      const int d = dist[u] + ext;

      for (const auto &v : adj[u]) {
        if (dist[v] == -1) {
          dist[v] = d + 1;
          dp[v][0] += dp[u][0];
          cur.emplace_back(std::array{v, 0});
        } else if (dist[v] == d + 1) {
          dp[v][0] += dp[u][0];
        } else if (dist[v] + 1 == d + 1) {
          dp[v][1] += dp[u][ext];
          if (!vis[v]) {
            vis[v] = 1;
            cur.emplace_back(std::array{v, 1});
          }
        }
      }
    }
    Q = std::move(cur);
  }

  std::cout << dp[T][1] << '\n';
}

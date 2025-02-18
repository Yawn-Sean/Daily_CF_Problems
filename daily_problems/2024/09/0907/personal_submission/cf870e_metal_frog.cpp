const int N = 2e5 + 7;
int edg[N], visNode[N], visEdge[N];
vector<int> G[N];

const ll mod = 1000000007;

ll modpow(ll b, ll e) {
  ll ans = 1;
  for (; e; b = b * b % mod, e /= 2)
    if (e & 1)
      ans = ans * b % mod;
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> disx, disy;
  vector<pii> edge;
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    edge.emplace_back(u, v);
    disx.emplace_back(u);
    disy.emplace_back(v);
  }
  sort(all(disx));
  sort(all(disy));
  disx.erase(unique(all(disx)), disx.end());
  disy.erase(unique(all(disy)), disy.end());
  for (int i = 0; i < n; i++) {
    auto [x, y] = edge[i];
    int u = lower_bound(all(disx), x) - disx.begin();
    int v = lower_bound(all(disy), y) - disy.begin();
    v += sz(disx);
    edg[i] = u ^ v;
    G[u].push_back(i);
    G[v].push_back(i);
  }
  int cntNode = 0, cntEdge = 0;
  auto dfs = [&](auto &&dfs, int u) -> void {
    visNode[u] = true;
    cntNode++;
    for (int eid : G[u]) {
      if (!visEdge[eid]) {
        cntEdge++;
        visEdge[eid] = true;
        int v = edg[eid] ^ u;
        if (!visNode[v])
          dfs(dfs, v);
      }
    }
  };
  ll ans = 1;
  for (int i = 0; i < sz(disx); i++) {
    cntEdge = cntNode = 0;
    if (!visNode[i]) {
      dfs(dfs, i);
      ll res = modpow(2, cntNode);
      if (cntNode > cntEdge) {
        res -= 1LL;
        res = (res + mod) % mod;
      }
      ans *= res;
      ans %= mod;
    }
  }
  for (int i = sz(disx); i < sz(disx) + sz(disy); i++) {
    cntEdge = cntNode = 0;
    if (!visNode[i]) {
      dfs(dfs, i);
      ll res = modpow(2, cntNode);
      if (cntNode > cntEdge) {
        res -= 1LL;
        res = (res + mod) % mod;
      }
      ans *= res;
      ans %= mod;
    }
  }
  cout << ans << "\n";
}

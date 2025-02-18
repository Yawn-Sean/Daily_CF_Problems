ll weight[N], dis[N], toRoot[N];
pii edge[N];
int startTime[N], endTime[N], T;
vector<int> tree[N];
Node *segTree, *segTreeDist;

void dfs(int u, int d) {
  startTime[u] = T++;
  dis[u] = d;
  segTreeDist->set(startTime[u], startTime[u] + 1, dis[u]);
  segTree->set(startTime[u], startTime[u] + 1, dis[u] + toRoot[u]);
  for (int eid : tree[u]) {
    auto [from, to] = edge[eid];
    dfs(to, d + weight[eid]);
  }
  endTime[u] = T;
}

void solve() {
  int n, q;
  cin >> n >> q;
  int eid = 0;
  for (eid = 0; eid < n - 1; eid++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edge[eid] = {u, v};
    weight[eid] = w;
    tree[u].emplace_back(eid);
  }
  for (; eid < 2 * n - 2; eid++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edge[eid] = {u, v};
    weight[eid] = w;
    toRoot[u] = w;
  }
  segTree = new Node(0, n + 7);
  segTreeDist = new Node(0, n + 7);
  dfs(0, 0);
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int eid, w;
      cin >> eid >> w;
      eid--;
      auto [from, to] = edge[eid];
      int diff = w - weight[eid];
      if (eid < n - 1) {
        segTreeDist->add(startTime[to], endTime[to], diff);
        segTree->add(startTime[to], endTime[to], diff);
      } else {
        segTree->add(startTime[from], startTime[from] + 1, diff);
      }
      weight[eid] = w;
    } else {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      ll distu = segTreeDist->query(startTime[u], startTime[u] + 1);
      ll distv = segTreeDist->query(startTime[v], startTime[v] + 1);
      ll ans = (1LL << 60);
      if (u == v)
        ans = 0;
      if (startTime[v] > startTime[u] && startTime[v] < endTime[u]) {
        ans = min(ans, distv - distu);
      }
      ll minToRoot = segTree->query(startTime[u], endTime[u]) - distu;
      ans = min(ans, minToRoot + distv);
      cout << ans << "\n";
    }
  }
}

int main() {
  int n; cin >> n;
  auto v = getv<int, int, int>(n);
  vector<int> p(n);
  iota(ALL(p), 0);
  auto s1D = [&] (vector<int> id) -> int {
    for (int i = 0; i < (int)id.size(); i += 2) {
      if (i == (int)id.size() - 1)
        return id[i];
      printf("%d %d\n", id[i] + 1, id[i + 1] + 1);
    }
    return -1;
  };
  auto s2D = [&] (vector<int> id) -> int {
    map<int, vector<int>> mp;
    for (auto e: id) {
      auto [x, y, z] = v[e];
      mp[y].emplace_back(e);
    }
    vector<int> res;
    for (auto &[k, vec]: mp) {
      sort(vec, [&] (int a, int b) {
        auto [x, y, z] = v[a];
        auto [xx, yy, zz] = v[b];
        return z < zz;
      });
      int cur = s1D(vec);
      if (cur != -1)
        res.push_back(cur);
    }
    return s1D(res);
  };
  auto s3D = [&] (vector<int> id) -> int {
    map<int, vector<int>> mp;
    for (auto e: id) {
      auto [x, y, z] = v[e];
      mp[x].emplace_back(e);
    }
    vector<int> res;
    for (auto &[k, vec]: mp) {
      sort(vec, [&] (int a, int b) {
        auto [x, y, z] = v[a];
        auto [xx, yy, zz] = v[b];
        return pair<int, int>{y, z} < pair<int, int>{yy, zz};
      });
      int cur = s2D(vec);
      if (cur != -1)
        res.push_back(cur);
    }
    return s1D(res);
  };
  s3D(p);
  return 0;
}

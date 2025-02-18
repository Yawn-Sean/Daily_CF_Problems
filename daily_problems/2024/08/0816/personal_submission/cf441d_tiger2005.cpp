int main() {
  int n, k; cin >> n;
  auto p = getv(n, 1);
  cin >> k;
  Union un(n);
  for (int i = 1; i <= n; i ++)
    un.link(i, p[i]);
  int delta = k - (n - un.size());
  vector<int> ans;
  if (delta < 0) {
    for (int t = 0; t < -delta; t ++) {
      for (int i = 1; i <= n; i ++) {
        vector<int> v;
        int pos = i;
        do {
          v.push_back(pos);
          pos = p[pos];
        } while (pos != i);
        if (v.size() != 1) {
          ans.push_back(i);
          v[0] = n + 1;
          ans.push_back(*min_element(ALL(v)));
          swap(p[i], p[ans.back()]);
          break;
        }
      }
    }
  }
  else {
    for (int t = 0; t < delta; t ++) {
      vector<int> vis(n + 1);
      int pos = 1;
      do {
        vis[pos] = true;
        pos = p[pos];
      } while (pos != 1);
      for (int i = 2; i <= n; i ++) if (!vis[i]) {
        ans.push_back(1);
        ans.push_back(i);
        swap(p[1], p[i]);
        break;
      }
    }
  }
  printf("%d\n", (int)ans.size() / 2);
  write(ans, "%d ", "\n");
  return 0;
}

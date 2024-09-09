void solve() {
  int n;
  cin >> n;
  unordered_map<string, int> hashmap;
  unordered_map<string, int> hashmap2;
  vector<string> ans(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      for (int len = 1; j + len <= s.length(); len++) {
        auto it = hashmap2.find(s.substr(j, len));
        if (it == hashmap2.end() || it->second != i) {
          hashmap[s.substr(j, len)]++;
          hashmap2[s.substr(j, len)] = i;
        }
      }
    }
    ans[i] = s;
  }
  for (auto &[s, cnt] : hashmap) {
    if (cnt == 1) {
      int i = hashmap2[s];
      if (s.length() < ans[i].length())
        ans[i] = s;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << "\n";
  }
}

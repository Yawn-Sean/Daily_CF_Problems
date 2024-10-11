int main() {
  vector<int> nxt(26, -1);
  vector<bool> occ(26);
  vector<bool> pointed(26);
  for (auto e: getv<string>(read())) {
    for (auto ele: e)
      occ[ele - 'a'] = true;
    for (int j = 1; j < (int)e.size(); j ++) {
      int f = e[j - 1] - 'a', t = e[j] - 'a';
      if (nxt[f] != -1 && nxt[f] != t)
        return puts("NO"), 0;
      nxt[f] = t;
    }
  }
  for (int i = 0; i < 26; i ++) if (nxt[i] != -1) {
    if (pointed[nxt[i]])
      return puts("NO"), 0;
    pointed[nxt[i]] = true;
  }
  vector<bool> vis(26);
  vector<string> ans;
  for (int i = 0; i < 26; i ++) if (!pointed[i]) {
    string s = "";
    int p = i;
    do {
      vis[p] = true;
      s += 'a' + p;
      p = nxt[p];
    } while (p != -1 && !vis[p]);
    if (p != -1)
      return puts("NO"), 0;
    if (occ[i])
      ans.push_back(s);
  }
  for (int i = 0; i < 26; i ++) if (!vis[i])
    return puts("NO"), 0;
  for (auto e: sorted(ans))
    printf("%s", e.c_str());
  return 0;
}

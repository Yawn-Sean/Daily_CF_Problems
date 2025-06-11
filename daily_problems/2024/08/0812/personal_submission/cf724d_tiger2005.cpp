int main() {
  int m; string s;
  cin >> m >> s;
  for (char c = 'a'; c <= 'z'; c ++) {
    bool flg = true;
    int cnt = 0;
    for (auto e: s)
      if (e <= c)
        cnt = 0;
      else if ((++ cnt) == m)
        flg = false;
    if (flg) {
      string ans = "";
      cnt = 0;
      int cnt2 = 0;
      for (auto e: s) {
        if (e < c)
          cnt = 0, ++ cnt2, ans += e;
        else {
          if (e == c)
            cnt2 = 0;
          else
            ++ cnt2;
          if ((++ cnt) == m)
            cnt = cnt2, ans += c;
        }
      }
      cout << sorted(ans) << endl;
      return 0;
    }
  }
  return 0;
}

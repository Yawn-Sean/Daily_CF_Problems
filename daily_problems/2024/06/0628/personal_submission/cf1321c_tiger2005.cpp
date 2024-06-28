int main() {
  auto [n, s] = reads<int, string>();
  int N = n;
  for (char c = 'z'; c > 'a' && n != 1; c --) {
    while (1) {
      string tmp = "";
      for (int i = 0; i < n; i ++) {
        bool flg = s[i] == c, flg2 = false;
        if (i != 0)
          flg2 |= s[i - 1] == c - 1;
        if (i != n - 1)
          flg2 |= s[i + 1] == c - 1;
        if (flg & flg2)
          ;
        else
          tmp += s[i];
      }
      if (s == tmp)
        break;
      s = tmp;
      n = s.size();
    }
  }
  printf("%d", N - n);
  return 0;
}

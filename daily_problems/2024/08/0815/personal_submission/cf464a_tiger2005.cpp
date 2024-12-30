int main() {
  int n, p; string s;
  cin >> n >> p >> s;
  if (p == 1)
    return puts("NO"), 0;
  if (p == 2) {
    if (s == "a")
      puts("b");
    else if (s == "ab")
      puts("ba");
    else
      puts("NO");
    return 0;
  }
  auto check = [&] (int i, char ch) {
    if (i > 0 && s[i - 1] == ch)
      return false;
    if (i > 1 && s[i - 2] == ch)
      return false;
    return true;
  };

  for (int i = n - 1; i >= 0; i --) {
    for (int j = s[i] - 'a' + 2; j <= p; j ++) {
      char c = j + 'a' - 1;
      if (check(i, c)) {
        s[i] = c;
        for (int k = i + 1; k < n; k ++) {
          for (int u = 1; u <= p; u ++)
            if (check(k, u + 'a' - 1)) {
              s[k] = u + 'a' - 1;
              break;
            }
        }
        printf("%s\n", s.c_str());
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}

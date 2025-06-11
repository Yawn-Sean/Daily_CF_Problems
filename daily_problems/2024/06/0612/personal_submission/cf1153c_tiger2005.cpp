int main() {
  int n = read();
  string s; cin >> s;
  // ( + x = ) + ? - x
  int x = 0;
  for (auto e: s)
    x += (e == '(' ? -1 : 1);
  x /= 2;
  for (auto &e: s) if (e == '?') {    
    if (x > 0)
      -- x, e = '(';
    else
      e = ')';
  }

  int cnt = 0;
  for (int i = 0; i < n; i ++)
    if ((cnt += (s[i] == '(' ? 1 : -1)) <= 0 && i != n - 1)
      return puts(":("), 0;

  if (cnt)
    return puts(":("), 0;
  cout << s;
  return 0;
}

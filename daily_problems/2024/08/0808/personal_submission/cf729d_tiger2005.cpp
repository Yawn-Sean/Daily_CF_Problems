int main() {
  int n, a, b, k; string s;
  cin >> n >> a >> b >> k >> s;
  int cnt = 0;
  vector<int> ans;
  for (auto [i, e]: index(s, 1)) {
    if (e == '0') {
      if (++ cnt == b)
        cnt = 0, ans.push_back(i);
    }
    else
      cnt = 0;
  }
  printf("%d\n", (int)ans.size() - (a - 1));
  write(vector<int>{a - 1 + ALL(ans)}, "%d ");
  return 0;
}

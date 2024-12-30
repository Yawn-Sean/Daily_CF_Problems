int main() {
  int n; i64 m;
  cin >> n >> m; -- m;
  vector<int> vl, vr;
  for (int i = 1; i < n; i ++) {
    if ((m >> (n - i - 1)) & 1)
      vr.push_back(i);
    else
      vl.push_back(i);
  }
  vr.push_back(n);
  write(vl, "%d ");
  write(reversed(vr), "%d ");
  return 0;
}

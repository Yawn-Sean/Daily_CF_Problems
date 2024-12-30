int main() {
  int n, k; cin >> n >> k;
  printf("%d\n", (6 * n - 1) * k);
  int l = 1, r = 2;
  for (int i = 0; i < n; i ++) {
    vector<int> tmp;
    for (int u: {0, 1, 2})
      tmp.push_back(l * k), l += 2;
    tmp.push_back(r * k), r += 6;
    write(sorted(tmp), "%d ", "\n");
  }
  return 0;
}

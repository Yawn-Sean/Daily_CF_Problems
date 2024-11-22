void solve() {
  int n;
  cin >> n;
  vector<int> num(n), prev(n), next(n), deleted(n);
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    prev[i] = (i == 0) ? (n - 1) : (i - 1);
    next[i] = (i + 1) % n;
  }
  queue<int> check;
  for (int i = 0; i < n; i++)
    check.push(i);
  vector<int> ans;
  while (!check.empty()) {
    int i = check.front();
    check.pop();
    if (deleted[i]) {
      continue;
    }
    int nextPtr = next[i];
    if (gcd(num[i], num[nextPtr]) == 1) {
      deleted[nextPtr] = true;
      next[i] = next[nextPtr];
      prev[next[i]] = i;
      ans.emplace_back(nextPtr);
      check.push(i);
    }
  }
  cout << ans.size() << " ";
  for (int x : ans) {
    cout << x + 1 << " ";
  }
  cout << "\n";
}

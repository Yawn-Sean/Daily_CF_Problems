int main() {
  int n, k; cin >> n >> k;
  printf("%d\n", 2 * ((n - 1) / k) + min((n - 1) % k, 2));
  queue<int> q;
  for (int i = 1; i <= k; i ++)
    q.push(i);
  for (int i = k + 1; i < n; i ++) {
    printf("%d %d\n", i, q.front());
    q.pop(); q.push(i);
  }
  while (!q.empty()) {
    printf("%d %d\n", n, q.front());
    q.pop();
  }
  return 0;
}

int main() {
  int n, k;
  cin >> n >> k;
  if (n < 1ll * k * (k + 1) / 2)
    return puts("NO"), 0;
  vector<int> v;
  int res = n - k * (k + 1) / 2;
  for (int i = 1; i <= k; i ++)
    v.push_back(res / k + i);
  res %= k;
  for (int i = k - 1; i; i --) {
    int num = min(res, 2 * v[i - 1] - v[i]);
    v[i] += num;
    res -= num;
  }
  if (res)
    puts("NO");
  else
    puts("YES"), write(v, "%d ");
  return 0;
}

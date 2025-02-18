int main() {
  int n; cin >> n;
  auto a = getv(n);
  if (n == 1)
    return puts("Alice"), 0;
  int l = 0, r = n - 1;
  while (l != n - 1 && a[l + 1] > a[l])
    ++ l;
  while (r != 0 && a[r - 1] > a[r])
    -- r;
  if ((l + 1) % 2 == 1 || (n - r) % 2 == 1)
    puts("Alice");
  else
    puts("Bob");
  return 0;
}

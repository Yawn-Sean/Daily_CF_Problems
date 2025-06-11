int main() {
  auto [l, r, x, y] = read<array<int, 4>>();
  l = (l + x - 1) / x;
  r /= x;
  if (y % x != 0)
    return puts("0"), 0;
  y /= x;

  int ans = 0;
  for (int i = 1; i * i <= y; i ++) if (y % i == 0)
    if (l <= i && i <= r && l <= (y / i) && (y / i) <= r && gcd(i, y / i) == 1)
      ans += 1 + (i * i != y);
  printf("%d", ans);

  return 0;
}

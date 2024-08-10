int main() {
  int a, b; cin >> a >> b;
  if (b == 1)
    return puts("0"), 0;
  Z ans = 0;
  for (int k = 1; k <= a; k ++) {
    Z l = Z(b) * k + 1, r = l * (b - 1);
    ans += (l + r) * (b - 1) / 2;
  }
  printf("%d\n", (int)ans);
  return 0;
}

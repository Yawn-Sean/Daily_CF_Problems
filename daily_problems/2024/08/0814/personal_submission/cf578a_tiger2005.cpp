int main() {
  int a, b; cin >> a >> b;
  if (a == b) {
    printf("%d\n",  a);
    return 0;
  }
  double ans = 1e18;
  double x = (a - b) / 2.0;
  if (x >= b)
    ckmin(ans, x / floor(x / b));
  x = (a + b) / 2.0;
  if (x >= b)
    ckmin(ans, x / floor(x / b));
  if (ans == 1e18)
    puts("-1");
  else
    printf("%.12f\n", ans);
  return 0;
}

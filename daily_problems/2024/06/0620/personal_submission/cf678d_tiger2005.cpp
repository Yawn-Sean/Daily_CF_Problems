int main() {
  auto [a, b, n, X] = reads<int, int, long long, int>();
  Z x(X);
  if (a == 1)
    x += Z(b) * n;
  else {
    Z y = Z(b) / (1 - a);
    x -= y;
    x *= Z(a).pow(n);
    x += y;
  }
  printf("%d", (int)x);
  return 0;
}

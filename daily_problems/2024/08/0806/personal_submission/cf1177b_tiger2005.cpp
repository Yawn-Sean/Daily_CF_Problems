int main() {
  i64 n; cin >> n;
  for (i64 l = 1, d = 1; ; l *= 10, ++ d) {
    i64 num = l * 9 * d;
    if (n <= num) {
      i64 loc = l + (n - 1) / d;
      i64 u = n - d * ((n - 1) / d);
      u = d - u;
      while (u --)
        loc /= 10;
      printf("%lld", loc % 10);
      break;
    }
    n -= num;
  }
  return 0;
}

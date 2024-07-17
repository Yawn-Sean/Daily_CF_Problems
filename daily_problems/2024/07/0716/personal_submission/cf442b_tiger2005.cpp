int main() {
  auto p = sorted(getv<double>(read()));
  reverse(p);
  double p0 = 1, p1 = 0;
  for (auto e: p) {
    if (p0 < p1)
      break;
    tie(p0, p1) = tuple{
      p0 * (1 - e),
      p1 * (1 - e) + p0 * e
    };
  }
  printf("%.12f\n", p1);
  return 0;
}

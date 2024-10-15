int main() {
  i64 y1, y2, yw, x, y, r;
  cin >> y1 >> y2 >> yw >> x >> y >> r;
  tie(y1, y2) = tuple{2 * yw - 2 * r - y2, 2 * yw - 2 * r - y1};
  i64 y0 = y2 - r;

  // kx + y0 - y = 0
  //     ~ (0, y1)

  // (y0 - y1)^2 / (k^2+1) >= r^2

  i128 U = (y0 - y1) * (y0 - y1);
  U *= (x * x);
  i128 D = (y - y0) * (y - y0) + x * x;

  if (U / D >= r * r)
    printf("%.15f\n", x - 1.0 * x / (y0 - y) * (yw - r - y));
  else
    puts("-1");
  return 0;
}

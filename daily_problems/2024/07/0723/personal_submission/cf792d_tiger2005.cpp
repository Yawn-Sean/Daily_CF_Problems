int main() {
  i64 n; cin >> n;
  multiCase() {
    i64 x;
    cin >> x;
    long long layer = 1;
    while (x % (layer << 1) == 0)
      layer <<= 1;
    for (auto e: read<string>()) {
      if (e == 'L') {
        if (layer == 1)
          continue;
        layer >>= 1;
        x -= layer;
      }
      else if (e == 'R') {
        if (layer == 1)
          continue;
        layer >>= 1;
        x += layer;
      }
      else {
        if (x == n / 2 + 1)
          continue;
        layer <<= 1;
        x = (x / (layer << 1) * 2 + 1) * layer;
      }
    }
    printf("%lld\n", x);
  }
  return 0;
}

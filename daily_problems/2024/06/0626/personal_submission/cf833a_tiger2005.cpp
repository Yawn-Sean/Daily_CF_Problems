int main() {
  multiCase() {
    i32 a, b; cin >> a >> b;
    i64 g = 1ll * a * b;
    i64 r = round(pow(g, 1.0/3));
    yOn(r * r * r == g && a % r == 0 && b % r == 0, "\n");
  }
  return 0;
}

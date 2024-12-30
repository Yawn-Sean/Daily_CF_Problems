int main() {
  vector<int> U(10, 2);
  for (auto [ch, num]: getv<char, int>(read())) {
    for (int i = 0; i < 10; i ++) {
      int g = (num >> i) & 1;
      if (ch == '&' && g == 0)
        U[i] = 0;
      if (ch == '^' && g == 1)
        U[i] ^= 1;
      if (ch == '|' && g == 1)
        U[i] = 1;
    }
  }
  int O = 0, X = 0;
  for (int i = 0; i < 10; i ++) {
    if (U[i] == 3)
      X ^= 1 << i;
    if (U[i] == 0)
      X ^= 1 << i, O ^= 1 << i;
    if (U[i] == 1)
      O ^= 1 << i;
  }
  printf("2\n| %d\n^ %d\n", O, X);
  return 0;
}

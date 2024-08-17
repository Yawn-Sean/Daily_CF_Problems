int main() {
  int n, q; cin >> n >> q;
  auto L = getv(n, 1);
  auto R = getv(n, 1);

  Union ul(n), ur(n);
  for (int i = 1; i < n; i ++) {
    if ((L[i] + L[i + 1]) % 2 == 0)
      ul.link(i, i + 1);
    if ((R[i] + R[i + 1]) % 2 == 0)
      ur.link(i, i + 1);
  }

  for (auto [a, b, c, d]: getv<array<int, 4>>(q)) {
    if ((L[a] + R[b]) % 2)
      puts("NO");
    else
      YES((ul[a] == ul[c] && ur[b] == ur[d]), "\n");
  }
  return 0;
}

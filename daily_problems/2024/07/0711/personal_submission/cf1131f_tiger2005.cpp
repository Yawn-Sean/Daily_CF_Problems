int main() {
  int n; cin >> n;
  vector<int> fin(n + 1), nxt(n + 1);
  for (int i = 1; i <= n; i ++)
    fin[i] = i;
  Union un(n);
  for (auto [a, b]: getv<int, int>(n - 1)) {
    a = un[a], b = un[b];
    nxt[fin[a]] = b;
    fin[a] = fin[b];
    un.link(b, a);
  }
  int rt = 0;
  for (int i = 1; i <= n; i ++) if (un[i] == i)
    rt = i;
  while (rt) {
    printf("%d ", rt);
    rt = nxt[rt];
  }
  return 0;
}

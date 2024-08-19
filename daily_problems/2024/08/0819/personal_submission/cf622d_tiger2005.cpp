int main() {
  int n; cin >> n;
  vector<int> odd, even;
  for (int i = 1; i < n; i ++)
    (i % 2 ? odd : even).push_back(i);
  write(odd, "%d ");
  if (n % 2 == 1)
    printf("%d ", n);
  write(reversed(odd), "%d ");
  printf("%d ", n);
  write(even, "%d ");
  if (n % 2 == 0)
    printf("%d ", n);
  write(reversed(even), "%d ");
  return 0;
}

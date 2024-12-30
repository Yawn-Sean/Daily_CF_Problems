int main() {
  int n; cin >> n;
  auto [T, _] = read<pair<long long, long long>>();
  auto q = reversed(sorted(getv<pair<long long, long long>>(n - 1)));
  int ans = n;

  int ptr = 0;
  multiset<long long> mts;
  while (1) {
    while (ptr != n - 1 && q[ptr].first > T) {
      mts.insert(q[ptr].second + 1 - q[ptr].first);
      ++ ptr;
    }
    ans = min(ans, (int)mts.size() + 1);
    if (mts.empty() || *mts.begin() > T)
      break;
    else {
      T -= *mts.begin();
      mts.erase(mts.begin());
    }
  }
  printf("%d\n", ans);
  return 0;
}

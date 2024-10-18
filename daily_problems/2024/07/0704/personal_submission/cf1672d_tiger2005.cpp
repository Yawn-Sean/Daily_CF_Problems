int main() {
  multiCase() {
    int n; cin >> n;
    auto a = getv(n);
    auto b = getv(n);
    map<int, int> mp;
    int ptr = 0;
    for (auto e: a) {
      if (e == b[ptr])
        ++ ptr;
      else
        ++ mp[e];
      while (ptr != n && ptr != 0 && b[ptr] == b[ptr - 1] && mp[b[ptr]])
        -- mp[b[ptr ++]];
    }
    YON(ptr == n, "\n");
  }
  return 0;
}

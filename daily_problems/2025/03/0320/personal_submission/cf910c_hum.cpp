#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> cnt(10), can(10, 1), vis(10), idx(10);
  iota(idx.begin(), idx.end(), 0);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int t = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      cnt[(s[i] - 'a')] += t;
      t *= 10;
    }
    can[s[0] - 'a'] = 0;
  }
  ranges::sort(idx, [&](int i, int j) { return cnt[i] > cnt[j]; });
  int res{};
  for (int i = 0; i < 10; i++) {
    int cur = idx[i];
    for (int j = 0; j < 10; j++) {
      if (j == 0 && !can[cur]) {
        continue;
      }
      if (vis[j]) {
        continue;
      }
      res += j * cnt[cur];
      vis[j] = 1;
      break;
    }
  }
  cout << res << '\n';
}

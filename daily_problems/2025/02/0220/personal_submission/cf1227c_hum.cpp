#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s, t{};
  cin >> s;

  for (int i = 0; i < k - 1; ++i) {
    t += "()";
  }
  for (int i = 0; i < n / 2 - (k - 1); ++i) {
    t += "(";
  }
  for (int i = 0; i < n / 2 - (k - 1); ++i) {
    t += ")";
  }

  vector<array<int, 2>> res;
  for (int i = 0; i < n; ++i) {
    int j = i;
    while (j < n && s[j] != t[i]) {
      j++;
    }
    if (i != j) {
      res.push_back({i, j});
      s[j] = s[i];
    }
  }
  cout << res.size() << endl;
  for (auto [i, j]: res) {
    cout << i + 1 << " " << j + 1 << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

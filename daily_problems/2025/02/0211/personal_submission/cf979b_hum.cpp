#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<array<int, 2>> a;
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    for (char c: s) {
      mp[c]++;
    }
    int m{};
    for (auto [c, cnt]: mp) {
      m = max(m, cnt);
    }
    if (n + m <= s.size()) m = m + n;
    else if (m == s.size() && n == 1) m = max(1, m - 1);
    else m = s.size();
    a.push_back({m, i});
  }
  vector<string> res{"Kuro", "Shiro", "Katie"};
  ranges::sort(a, greater());
  if (a[0][0] == a[1][0]) {
    cout << "Draw" << endl;
  } else {
    cout << res[a[0][1]] << endl;
  }
}

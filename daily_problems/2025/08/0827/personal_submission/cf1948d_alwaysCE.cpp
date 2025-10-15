#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int ans = 0;
    int n = s.size();
    auto ok = [&](char a, char b) { return (a == b || a == '?' || b == '?'); };
    for (int L = n / 2; L >= 1; L--) {
      if (2 * L <= ans) {
        break;
      }

      int cnt = 0;
      for (int j = 0; j <= n - L - 1; j++) {
        if (ok(s[j], s[j + L])) {
          ++cnt;
        } else {
          cnt = 0;
        }
        if (cnt >= L) {
          ans = 2 * L;
          goto out;
        }
      }
    out: {}
    }
    cout << ans << endl;
  }
  return 0;
}

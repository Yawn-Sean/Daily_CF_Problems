#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::ios_base;
using std::min;
using std::string;
using std::vector;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;

  string s, t;
  cin >> s >> t;

  vector<int> cnt(26);
  auto add = [&](char c1, char c2, char c3, char c4) {
    ++cnt[c1 - 'a'];
    ++cnt[c2 - 'a'];
    ++cnt[c3 - 'a'];
    ++cnt[c4 - 'a'];
  };
  auto reset = [&](char c1, char c2, char c3, char c4) {
    cnt[c1 - 'a'] = 0;
    cnt[c2 - 'a'] = 0;
    cnt[c3 - 'a'] = 0;
    cnt[c4 - 'a'] = 0;
  };

  auto op = [&](char c1, char c2, char c3, char c4) {
    int ans = 2;
    // change c1-> ?, c2 -> ?
    // check cnt[] % 2 == 0 for all characters
    for (auto& nc1 : {c1, c2, c3, c4}) {
      int num_change1 = 0;
      if (nc1 != c1) {
        ++num_change1;
      }
      for (auto& nc2 : {c1, c2, c3, c4}) {
        int num_change2 = 0;
        if (nc2 != c2) {
          ++num_change2;
        }
        add(nc1, nc2, c3, c4);
        if (cnt[nc1 - 'a'] % 2 == 0 && cnt[nc2 - 'a'] % 2 == 0 &&
            cnt[c3 - 'a'] % 2 == 0 && cnt[c4 - 'a'] % 2 == 0) {
          ans = min(ans, num_change1 + num_change2);
        }
        reset(nc1, nc2, c3, c4);
      }
    }
    return ans;
  };

  int ans = 0;
  for (int i = 0; i < n / 2; i++) {
    char c1 = s[i], c2 = s[n - 1 - i];
    char c3 = t[i], c4 = t[n - 1 - i];
    ans += op(c1, c2, c3, c4);
  }
  if (n & 1) {
    ans += (s[n / 2] != t[n / 2]);
  }
  cout << ans << '\n';
  return 0;
}

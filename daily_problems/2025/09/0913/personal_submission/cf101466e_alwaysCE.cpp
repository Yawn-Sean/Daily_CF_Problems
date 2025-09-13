#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int MX = 1e6;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  string text;
  getline(cin, text);

  string pattern;
  getline(cin, pattern);

  int need;
  cin >> need;

  auto kmp = [&](const string &s, int m) {
    int n = (int)s.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
      if (pattern[i] == pattern[len]) {
        lps[i++] = ++len;
      } else {
        if (len) {
          len = lps[len - 1];
        } else {
          lps[i++] = 0;
        }
      }
    }
    int occ = 0;
    for (int i = 0, j = 0; i < n;) {
      if (s[i] == pattern[j]) {
        i++;
        j++;
      }
      if (j == m) {
        occ++;
        j = lps[j - 1];
      } else if (i < n && s[i] != pattern[j]) {
        if (j) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }
    }
    return occ;
  };

  int ans = -1;
  int left = 0, right = (int)pattern.size();
  while (left < right) {
    int mid = (left + right) / 2;
    int occ = kmp(text, mid + 1);
    if (occ >= need) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  if (ans == -1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  cout << pattern.substr(0, ans + 1) << endl;
  return 0;
}

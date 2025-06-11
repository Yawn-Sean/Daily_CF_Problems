#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s, c;
    cin >> s >> c;
    int n = s.size();
    vector suf(n, n - 1);
    for (int i = n - 2; i >= 0; --i) {
      suf[i] = suf[i + 1];
      if (s[i] < s[suf[i + 1]]) {
        suf[i] = i;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      if (s[i] > s[suf[i + 1]]) {
        swap(s[i], s[suf[i + 1]]);
        break;
      }
    }
    if (s < c) {
      cout << s << "\n";
    } else {
      cout << "---" << "\n";
    }
  }
}

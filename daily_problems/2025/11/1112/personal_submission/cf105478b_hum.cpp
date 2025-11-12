#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;

    cin >> n >> s;

    int ans = 0, flg = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        ans += 1 + flg;
        flg = 0;
      } else if (i && s[i - 1] != '?') {
        if (i + 1 < n && s[i + 1] != '?' && s[i - 1] != s[i + 1])
          ans++;
        else if (i + 1 < n && s[i + 1] == '?')
          flg = 1;
      }
    }

    cout << ans << '\n';
  }
}

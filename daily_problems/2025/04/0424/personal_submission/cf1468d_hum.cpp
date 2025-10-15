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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> s(m);
    for (int i = 0; i < m; i++) {
      cin >> s[i];
    }
    ranges::sort(s);
    vector<int> tmp;
    int x{};
    if (a < b) {
      x = b - 1;
    } else {
      x = n - b;
    }
    for (int i = 0; i < min(abs(a - b) - 1, m); i++) {
      tmp.push_back(x - i);
    }
    ranges::reverse(tmp);
    int j{}, res{};
    for (int i = 0; i < m; i++) {
      while (j < tmp.size() && tmp[j] <= s[i]) {
        j++;
      }
      if (j != tmp.size()) {
        res++;
        j++;
      }
    }
    cout << res << endl;
  }
}

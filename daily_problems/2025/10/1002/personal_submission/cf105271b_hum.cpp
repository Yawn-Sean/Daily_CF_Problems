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

  auto query = [&](int i, int x) -> bool {
    cout << "? " << i + 1 << ' ' << x << endl;
    char c;
    cin >> c;
    return c == '<';
  };

  int n;
  cin >> n;

  vector<int> ans(n);

  int cur = 1;
  for (int i = 0; i < n; i++) {
    while (query(i, cur)) cur++;
    ans[i] = cur;
  }

  cout << '!';
  for (auto &x: ans) cout << ' ' << x;
}

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

  int n, m;
  cin >> n >> m;

  vector<int> idxs1, idxs2;

  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (x < y) idxs1.emplace_back(i);
    else idxs2.emplace_back(i);
  }

  cout << "YES\n";
  if (idxs1.size() > idxs2.size()) {
    cout << idxs1.size() << '\n';
    for (auto &v: idxs1) cout << v << ' ';
  } else {
    cout << idxs2.size() << '\n';
    for (auto &v: idxs2) cout << v << ' ';
  }
}

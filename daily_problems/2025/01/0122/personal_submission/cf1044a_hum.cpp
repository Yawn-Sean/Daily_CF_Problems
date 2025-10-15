#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vs(n);
  for (auto &x: vs) {
    cin >> x;
  }

  ranges::sort(vs);
  vs.push_back(1e9);
  vector<int> hs;
  for (int i = 0; i < m; i++) {
    int x1, x2, y;
    cin >> x1 >> x2 >> y;
    if (x1 == 1) hs.push_back(x2);
  }
  ranges::sort(hs);
  int k = hs.size();
  int res = k;
  for (int i = 0, j = 0; i <= n; i++) {
    while (j < k && hs[j] < vs[i]) j++;
    res = min(res, i + k - j);
  }
  cout << res << endl;
  return 0;
}

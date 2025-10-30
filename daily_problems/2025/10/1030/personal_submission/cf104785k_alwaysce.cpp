#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int MX = 1e6;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  /*
    If you can categorize the edges into two parts and both have no cyclical
    dependencies, at least one of them has more than m/2 edges.
  */

  int cnt0 = 0, cnt1 = 0;
  vector<pair<int, int>> edges(m);
  vector<int> idxs1, idxs2;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    edges[i] = {u, v};
    if (u > v) {
      ++cnt0;
      idxs1.push_back(i);
    } else {
      ++cnt1;
      idxs2.push_back(i);
    }
  }

  cout << "YES\n";
  if (cnt0 > cnt1) {
    cout << cnt0 << "\n";
    for (auto& i : idxs1) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  } else {
    cout << cnt1 << "\n";
    for (auto& i : idxs2) {
      cout << i + 1 << " ";
    }
    cout << "\n";
  }

  return 0;
}

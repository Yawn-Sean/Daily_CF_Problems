#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gq;
vector<int> be;

int dfs(int q, int p) {
  if (be[q]) return q;
  for (int g: gq[q]) {
    if (g != p) {
      if (int d = dfs(g, q); d >= 0) return d;
    }
  }
  return -1;
}

void solve() {
  int n, g, q;
  cin >> n;

  gq.resize(n), be.assign(n, 0);
  for (int i = 1; i < n; i++) {
    cin >> g >> q;
    gq[g - 1].push_back(q - 1);
    gq[q - 1].push_back(g - 1);
  }
  cin >> g;
  while (g--) {
    cin >> q;
    be[q - 1] = 1;
  }
  vector<int> ba(n);
  cin >> g;
  while (g--) {
    cin >> q;
    ba[q - 1] = 1;
  }
  cout << "B " << q << endl;
  cin >> q;
  int h = dfs(q - 1, q - 1);
  cout << "A " << h + 1 << endl;
  cin >> q;
  cout << "C " << (ba[q - 1] ? h + 1 : -1) << endl;
  gq.clear();
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}

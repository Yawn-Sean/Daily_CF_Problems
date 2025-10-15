#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Fenwick {
  vector<int> bit;
  int n;

  Fenwick(int n) {
    this->n = n;
    bit.assign(n, 0);
  }

  int preMax(int r) {
    int ret = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) ret = max(ret, bit[r]);
    return ret;
  }

  void update(int idx, int delta) {
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] = max(bit[idx], delta);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> v1(n * k), v2(n * k);
  for (int i = 0; i < n * k; i++) {
    cin >> v1[i];
  }

  for (int i = 0; i < n * k; i++) {
    cin >> v2[i];
  }

  vector<vector<int>> pos(n + 1);
  for (int i = n * k - 1; i >= 0; i--) {
    pos[v2[i]].push_back(i);
  }

  Fenwick fen(n * k + 1);
  for (int i = 0; i < n * k; i++) {
    int val = v1[i];
    for (int j : pos[val]) {
      fen.update(j + 1, fen.preMax(j) + 1);
    }
  }

  cout << fen.preMax(n * k) << '\n';
  return 0;
}

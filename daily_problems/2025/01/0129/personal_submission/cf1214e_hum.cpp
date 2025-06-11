#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> idx(n);
  ranges::iota(idx, 0);
  ranges::sort(idx, [&](int i, int j) { return a[i] > a[j]; });

  vector<int> tmp(n);
  for (int i = 0; i < n; i++) {
    tmp[i] = idx[i] * 2 + 1;
  }
  for (int i = 0; i < n - 1; i++) {
    cout << tmp[i] << " " << tmp[i + 1] << "\n";
  }

  for (int i = 0; i < n; i++) {
    int p = idx[i], dis = a[p];
    int u = 2 * p + 2, v = tmp[i + dis - 1];
    cout << u << " " << v << "\n";
    if (tmp.back() == v) {
      tmp.push_back(u);
    }
  }
}

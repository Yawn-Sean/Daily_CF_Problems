#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int q = sqrt(n);
  vector<int> a(n);
  ranges::iota(a, 1);
  for (int i = 0; i < n; i += q) {
    ranges::reverse(a.begin() + i, a.begin() + min(n, i + q));
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
}

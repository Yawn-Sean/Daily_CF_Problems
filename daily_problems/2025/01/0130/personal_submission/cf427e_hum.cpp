#include <bits/stdc++.h>
using namespace std;

using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++)cin >> a[i];
  ranges::sort(a);
  int pos = a[n / 2];
  i64 res = 0;
  for (int i = 0; i < n / 2; i += m) {
    res += abs(a[i] - pos);
  }
  for (int i = n - 1; i > n / 2; i -= m) {
    res += abs(a[i] - pos);
  }
  cout << res * 2 << endl;
}

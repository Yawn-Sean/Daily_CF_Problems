#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    b[i] += a[i];
  }

  for (int i = 1; i < n; i++) {
    b[i] = min(b[i], b[i - 1] + 1);
  }
  for (int i = n - 2; i >= 0; i--) {
    b[i] = min(b[i], b[i + 1] + 1);
  }
  long long res{};
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      cout << -1 << endl;
      return 0;
    }
    res += b[i] - a[i];
  }
  cout << res << endl;
  for (int i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
}

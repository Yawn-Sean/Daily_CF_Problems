#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  int m{};
  long long s{};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
    s += a[i];
  }

  if (m > (s - m) * 2) {
    cout << s - m << endl;
  } else {
    cout << s / 3 << endl;
  }
}

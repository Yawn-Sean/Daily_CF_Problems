#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    mp[b[i]]++;
  }
  int sum{};
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      sum++;
    }
  }
  int m;
  cin >> m;
  long long res{1};
  for (auto [k, v]: mp) {
    for (int j = 1; j <= v; ++j) {
      int t = j;
      if (sum > 0 && t % 2 == 0) {
        sum--;
        t /= 2;
      }
      res = res * t % m;
    }
  }
  cout << res << endl;
}

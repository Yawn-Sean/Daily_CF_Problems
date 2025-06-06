#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  int m = n / k;
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  int mod = 1e9 + 7;
  long long v = 1;
  for (int i = 0; i < k - 1; i++)
    v = v * 10;

  auto div = [&](long long x, int y) -> long long {
    return (x >= 0 ? x / y + 1 : 0);
  };

  long long res{1};
  for (int i = 0; i < n / k; i++) {
    res = (div(v * 10 - 1, a[i]) - (div(v * (b[i] + 1) - 1, a[i]) - div(v * b[i] - 1, a[i]))) % mod * res % mod;
  }

  cout << (res + mod) % mod;
}

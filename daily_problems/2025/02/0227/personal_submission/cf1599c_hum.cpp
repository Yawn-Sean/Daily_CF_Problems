#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  double p;
  cin >> n >> p;
  for (int i = 0; i <= n; i++) {
    double res = 0;
    res += i * (i - 1) * (i - 2) / 6;
    res += i * (i - 1) / 2 * (n - i);
    res += 0.5 * i * (n - i) * (n - i - 1) / 2;
    if (res / (n * (n - 1) * (n - 2) / 6) >= p) {
      cout << i;
      break;
    }
  }
}

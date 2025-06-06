#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n;
  cin >> n;

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (gcd(i, n / i) == 1) {
        cout << "YES\n2\n";
        for (int j = 1; j < i; j++) {
          long long r = n - 1 - j * n / i;
          if (r % i == 0) {
            cout << j << " " << i << "\n";
            cout << r / i << " " << n / i << "\n";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
}

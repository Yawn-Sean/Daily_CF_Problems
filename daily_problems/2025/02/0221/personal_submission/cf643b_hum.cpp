#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  if (k - n < 1 || n == 4) {
    cout << -1 << endl;
    return 0;
  }
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << a << " " << c;
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) {
      cout << " " << i;
    }
  }
  cout << " " << d << " " << b << endl;


  cout << c << " " << a;
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) {
      cout << " " << i;
    }
  }
  cout << " " << b << " " << d;
}

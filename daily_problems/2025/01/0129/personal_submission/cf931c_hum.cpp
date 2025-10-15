#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ranges::sort(a);
  int mi = a[0], ma = a[n - 1];
  if (ma - mi != 2) {
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      cout << a[i] << " ";
    }
  } else {
    int c1 = 0, c3 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == mi) {
        c1++;
      } else if (a[i] == ma) {
        c3++;
      }
    }
    int c2 = n - c1 - c3;
    if (min(c1, c3) > c2 / 2) {
      cout << n - min(c1, c3) * 2 << endl;;
      for (int i = 0; i < min(c1, c3); i++) {
        a[i] = mi + 1;
        a[n - i - 1] = ma - 1;
      }
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
    } else {
      cout << n - c2 / 2 * 2 << endl;;
      for (int i = 0; i < n; i++) {
        if (a[i] == mi + 1 && a[i + 1] == ma - 1) {
          cout << mi << " " << ma << " ";
          i++;
        } else {
          cout << a[i] << " ";
        }
      }
    }
  }
}

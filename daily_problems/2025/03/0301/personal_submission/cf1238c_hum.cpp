#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int h, n;
    cin >> h >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    a[n] = 0;
    int cur = 0;
    int res{};
    while (cur < n - 1) {
      if (a[cur + 1] - a[cur + 2] == 1) {
        cur += 2;
      } else {
        res++;
        cur += 1;
      }
    }
    cout << res << "\n";
  }
}

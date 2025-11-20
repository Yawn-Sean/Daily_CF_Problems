#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  vector<int> lis;
  for (int i = 0; i < n; i++) {
    int u = a[i], v = b[i];

    auto it1 = lower_bound(lis.begin(), lis.end(), u);
    int pos1 = it1 - lis.begin();

    auto it2 = lower_bound(lis.begin(), lis.end(), v);
    int pos2 = it2 - lis.begin();

    if (pos1 == pos2) {
      if (pos1 == lis.size()) {
        lis.push_back(min(u, v));
      } else {
        lis[pos1] = min(lis[pos1], min(u, v));
      }
    } else {
      if (pos1 == lis.size()) {
        lis.push_back(u);
      } else {
        lis[pos1] = min(lis[pos1], u);
      }

      if (pos2 == lis.size()) {
        lis.push_back(v);
      } else {
        lis[pos2] = min(lis[pos2], v);
      }
    }
  }
  cout << lis.size() << '\n';
  return 0;
}

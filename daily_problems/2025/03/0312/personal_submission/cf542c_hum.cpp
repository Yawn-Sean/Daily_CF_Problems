#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int m{};
  long long res{1};
  for (int i = 0; i < n; i++) {
    vector<int> vis(n);
    int x = a[i], idx = 1;
    vis[x] = idx;
    x = a[x];
    while (vis[x] == 0) {
      vis[x] = ++idx;
      x = a[x];
    }
    m = max(m, vis[x]);
    long long t = idx - vis[x] + 1;
    res = lcm(res, t);
  }
  long long add{res};

  while (res < m) {
    res += add;
  }

  cout << res << '\n';
}

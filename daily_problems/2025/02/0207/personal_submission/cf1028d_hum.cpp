#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  set<int> a;
  int inf = 1e9;
  a.insert(inf), a.insert(-inf);
  int cnt = 0;
  int l = -inf, r = inf;
  i64 res{1};
  int mod = 1e9 + 7;

  for (int i = 0; i < n; i++) {
    string s;
    int v;
    cin >> s >> v;
    if (s == "ADD") {
      a.insert(v);
      if (l < v && v < r) {
        cnt++;
      }
    } else {
      if (v < l || v > r) {
        cout << 0 << endl;
        return 0;
      }
      if (l < v && v < r) {
        res = res * 2 % mod;
      }
      auto it = a.find(v);
      l = *prev(it);
      r = *next(it);
      a.erase(it);
      cnt = 0;
    }
  }
  cout << res * (cnt + 1) % mod << endl;
}

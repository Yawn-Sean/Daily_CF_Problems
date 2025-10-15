#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<int, vector<array<int, 3>>> mps;
  unordered_map<int, vector<array<int, 2>>> mpe;
  int n, w, h;
  cin >> n >> w >> h;
  for (int i = 0; i < n; i++) {
    int g, p, t;
    cin >> g >> p >> t;
    if (g == 1) {
      mps[p - t].push_back({p, 0, i});
      mpe[p - t].push_back({p, h});
    } else {
      mps[p - t].push_back({0, p, i});
      mpe[p - t].push_back({w, p});
    }
  }
  vector<array<int, 2>> res(n);

  for (auto &[_, ps]: mps) {
    ranges::sort(ps, [](auto &a, auto &b) {
      return a[0] - a[1] < b[0] - b[1];
    });
    vector<array<int, 2>> es = mpe[_];
    ranges::sort(es, [](auto &a, auto &b) {
      return a[0] - a[1] < b[0] - b[1];
    });

    for (int i = 0; i < ps.size(); i++) {
      res[ps[i][2]] = {es[i][0], es[i][1]};
    }
  }
  for (auto &[a, b]: res) {
    cout << a << ' ' << b << '\n';
  }
}

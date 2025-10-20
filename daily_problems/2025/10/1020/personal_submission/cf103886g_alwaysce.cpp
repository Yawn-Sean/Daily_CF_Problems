#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  auto dfs = [&](auto&& dfs, int x) -> vector<int> {
    if (x == 1) {
      return {1};
    }

    vector<int> ans;
    for (auto& v: dfs(dfs, x / 2)) {
      ans.push_back(2 * v);
    }

    for (auto& v: dfs(dfs, x - x / 2)) {
      ans.push_back(2 * v - 1);
    }
    return ans;
  };

  auto res = dfs(dfs, n);
  for (auto& x: res) {
    cout << x << ' ';
  }
  return 0;
}

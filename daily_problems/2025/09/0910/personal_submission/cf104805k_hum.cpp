#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  long long l;
  cin >> n >> l;
  l++;
  vector<int> vals(16);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    vals[x] = 1;
  }

  set<long long> vis = {1};
  function<void(long long)> dfs = [&](long long cur) {
    for (int i = 2; i < 16; i++) {
      if (vals[i]) {
        long long ncur = cur * (i + 1);
        if (ncur <= l && !vis.contains(ncur)) {
          vis.insert(ncur);
          dfs(ncur);
        }
      }
    }
  };

  dfs(1);
  cout << vis.size() - 1 << '\n';
}

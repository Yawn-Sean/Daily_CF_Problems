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
  cin >> n;

  vector<int> nums(n);
  int g = 0;
  for (auto &x: nums) {
    cin >> x;
    g = gcd(x, g);
  }

  for (auto &x: nums)
    x /= g;

  int M = ranges::max(nums);
  vector<int> pr(M + 1);
  iota(pr.begin(), pr.end(), 0);

  for (int i = 2; i <= M; i++) {
    if (pr[i] == i) {
      for (int j = i; j <= M; j += i) {
        pr[j] = i;
      }
    }
  }

  vector<int> vis(M + 1, 0);

  for (auto &x: nums) {
    while (x > 1) {
      int p = pr[x];
      if (vis[p]) return cout << "NO", 0;
      vis[p] = 1;
      while (x % p == 0) x /= p;
    }
  }

  cout << "YES";
}

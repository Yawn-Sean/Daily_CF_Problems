#include <bits/stdc++.h>
#include <cstdio>
#include <unordered_set>
#define REP(i, j) for (int i = 0; i < j; ++i)
using namespace std;
using ll = int64_t;
  int seq[200005];
int no() {
  printf("NO");
  return 0;
}
int main() {
  int n, x = 0, y = 0, k = 0, t = 0;
  cin >> n;
  unordered_set<int> s;
  REP(i, n) {
    cin >> seq[i];
    seq[i]--;
    if (i) {
      s.insert(abs(seq[i] - seq[i - 1]));
    }
  }
  if (n == 1) {
    cout << "YES\n" << 1 << ' ' << seq[0] + 1;
    return 0;
  }
  if (s.size() > 2 || s.count(0)) {
    return no();
  }
  for (auto &i : s)
    k ^= i;
  if (s.size() == 2) {
    if (s.count(1)) {
      k ^= 1;
    } else {
      return no();
    }
  }
  REP(i, n - 1) {
    int x1 = seq[i] / k;
    int y1 = seq[i] % k;
    int x2 = seq[i + 1] / k;
    int y2 = seq[i + 1] % k;
    int dis = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
    if (dis != 1) {
      return no();
    }
    t = max(t, max(x1, x2));
  }
  cout << "YES\n";
  cout << t + 1 << ' ' << max(1, k) << '\n';
}
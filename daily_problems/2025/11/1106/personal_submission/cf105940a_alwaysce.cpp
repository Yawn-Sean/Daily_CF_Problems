#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1000000007LL;
const int N = 81;

inline int id(int s, int c0, int c1, int c2) {
  return (((s * 3 + c0) * 3 + c1) * 3 + c2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  vector<int> ds(t);
  int Dmax = 0;
  for (int i = 0; i < t; ++i) {
    cin >> ds[i];
    Dmax = max(Dmax, ds[i]);
  }

  static int nxt[N][3];
  for (int s = 0; s < 3; ++s)
    for (int c0 = 0; c0 < 3; ++c0)
      for (int c1 = 0; c1 < 3; ++c1)
        for (int c2 = 0; c2 < 3; ++c2) {
          int from = id(s, c0, c1, c2);
          for (int tval = 0; tval < 3; ++tval) {
            int s2 = (s + tval) % 3;
            int nc0 = c0, nc1 = c1, nc2 = c2;
            if (s2 == 0)
              nc0 = (nc0 + 1) % 3;
            else if (s2 == 1)
              nc1 = (nc1 + 1) % 3;
            else
              nc2 = (nc2 + 1) % 3;
            nxt[from][tval] = id(s2, nc0, nc1, nc2);
          }
        }

  static bool good[N];
  for (int s = 0; s < 3; ++s)
    for (int c0 = 0; c0 < 3; ++c0)
      for (int c1 = 0; c1 < 3; ++c1)
        for (int c2 = 0; c2 < 3; ++c2) {
          int u = id(s, c0, c1, c2);
          int cnt2 = (c0 == 2) + (c1 == 2) + (c2 == 2);
          good[u] = (cnt2 % 3) == 0;
        }

  static i64 ans[100000 + 5];
  static i64 v[N], nv[N];

  memset(v, 0, sizeof(v));
  v[id(0, 1, 0, 0)] = 1;

  auto step = [&](const int w0, const int w1, const int w2) {
    memset(nv, 0, sizeof(nv));
    for (int from = 0; from < N; ++from) {
      i64 ways = v[from];
      if (!ways) continue;
      int to0 = nxt[from][0];
      int to1 = nxt[from][1];
      int to2 = nxt[from][2];
      nv[to0] = (nv[to0] + ways * w0) % MOD;
      nv[to1] = (nv[to1] + ways * w1) % MOD;
      nv[to2] = (nv[to2] + ways * w2) % MOD;
    }
    memcpy(v, nv, sizeof(v));
  };

  if (Dmax >= 1) {
    step(3, 3, 3);
    i64 sum = 0;
    for (int u = 0; u < N; ++u)
      if (good[u]) sum = (sum + v[u]) % MOD;
    ans[1] = sum;

    for (int d = 2; d <= Dmax; ++d) {
      step(4, 3, 3);
      i64 ssum = 0;
      for (int u = 0; u < N; ++u)
        if (good[u]) ssum = (ssum + v[u]) % MOD;
      ans[d] = ssum;
    }
  }

  for (int i = 0; i < t; ++i) {
    cout << ans[ds[i]] << '\n';
  }
  return 0;
}

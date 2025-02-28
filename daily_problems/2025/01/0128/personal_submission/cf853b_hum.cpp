#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e12;
int M = 1e6 + 5;


int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<array<int, 4>> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
  }
  ranges::sort(a);
  vector<i64> pre(M, inf * n), suf(M, inf * n), st(n + 1, inf), ed(n + 1, inf);

  int j = 0;
  for (int i = 1; i < M - k; i++) {
    pre[i] = pre[i - 1];
    while (j < m && a[j][0] < i) {
      if (a[j][2] == 0 && st[a[j][1]] > a[j][3]) {
        pre[i] -= st[a[j][1]] - a[j][3];
        st[a[j][1]] = a[j][3];
      }
      j++;
    }
  }

  j = m - 1;
  for (int i = M - 1 - k; i > 0; i--) {
    suf[i] = suf[i + 1];
    while (j >= 0 && a[j][0] >= i + k) {
      if (a[j][1] == 0 && ed[a[j][2]] > a[j][3]) {
        suf[i] -= ed[a[j][2]] - a[j][3];
        ed[a[j][2]] = a[j][3];
      }
      j--;
    }
  }

  i64 res = inf;
  for (int i = 1; i <= M - k; i++) {
    res = min(res, pre[i] + suf[i]);
  }
  cout << (res == inf ? -1 : res) << endl;
}

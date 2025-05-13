/*
  https://codeforces.com/problemset/problem/67/B
  kaicheng
  2025-05-13
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define int long long
#define itn int

const int MAXN = 1005;
int bit[MAXN];
int n;

void update(int idx, int delta) {
  for (; idx <= n; idx += idx & (-idx)) {
    bit[idx] += delta;
  }
}

int query(int idx) {
  int sum = 0;
  idx = min(idx, n);
  for (; idx > 0; idx -= idx & (-idx)) {
    sum += bit[idx];
  }
  return sum;
}

void solve() {
  int k;
  cin >> n >> k;

  vector<int> b(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  for (int i = 0; i <= n; ++i) {
    bit[i] = 0;
  }

  set<int> available;
  for (int i = 1; i <= n; ++i) {
    available.insert(i);
  }

  vector<int> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    for (int x : available) {
      int count_ge_xk = query(n) - query(min(n, x + k - 1));
      if (count_ge_xk == b[x]) {
        a[i] = x;
        available.erase(x);
        update(x, 1);
        break;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << a[i] << (i == n ? "" : " ");
  }
  cout << '\n';
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tt;
  // cin >> tt;
  tt = 1;
  while (tt--) {
    solve();
  }
  return 0;
}
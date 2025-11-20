#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int B = 31;

struct Trie {
  vector<array<int, 2>> ch;
  vector<int> mx;

  Trie(int n) {
    ch.reserve(n * 32);
    mx.reserve(n * 32);
    newNode();
  }
  int newNode() {
    ch.push_back({-1, -1});
    mx.push_back(-1);
    return (int)ch.size() - 1;
  }
  void insert(int x, int id) {
    int u = 0;
    mx[u] = max(mx[u], id);
    for (int b = B - 1; b >= 0; --b) {
      int bit = (x >> b) & 1;
      if (ch[u][bit] == -1) ch[u][bit] = newNode();
      u = ch[u][bit];
      mx[u] = max(mx[u], id);
    }
  }
  int query(int x, int lim) {
    int u = 0, res = -1;
    for (int b = B - 1; b >= 0; --b) {
      int xb = (x >> b) & 1;
      int lb = (lim >> b) & 1;
      if (lb) {
        int go = xb;
        if (ch[u][go] != -1) res = max(res, mx[ch[u][go]]);
      }
      int nxt = xb ^ lb;
      if (ch[u][nxt] == -1) return res;
      u = ch[u][nxt];
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  auto solve = [&](int lim) -> i64 {
    Trie t(n);
    i64 ans = 0;
    int bad = -1;
    for (int r = 0; r < n; r++) {
      int id = t.query(a[r], lim);
      bad = max(bad, id);
      if (r > 0) ans += max(0, r - 1 - bad);
      t.insert(a[r], r);
    }
    return ans;
  };

  cout << solve(k) - solve(k + 1) << '\n';
  return 0;
}

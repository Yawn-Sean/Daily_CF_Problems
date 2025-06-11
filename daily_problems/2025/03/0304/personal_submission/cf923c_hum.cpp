#include <bits/stdc++.h>
using namespace std;

struct Trie {
  int N;
  int idx{};
  vector<array<int, 2>> son;
  vector<int> cnt;

  Trie(int n) {
    init(n);
  }

  void init(int n_) {
    N = n_ + 5;
    son.assign(N, array<int, 2>{});
    cnt.assign(N, 0);
  }

  void insert(int s) {
    int p = 0;
    for (int i = 29; i >= 0; i--) {
      int u = s >> i & 1;
      if (son[p][u] == 0) {
        son[p][u] = ++idx;
      }
      p = son[p][u];
      cnt[p]++;
    }
  }

  int query(int s) {
    int p = 0;
    int res{};
    for (int i = 29; i >= 0; i--) {
      int u = s >> i & 1;
      if (cnt[son[p][u]] == 0) {
        u = u ^ 1;
      }
      res = res << 1 | u;
      p = son[p][u];
      cnt[p]--;
    }
    return res ^ s;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  Trie trie(n * 30);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    trie.insert(b[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << trie.query(a[i]) << " ";
  }
}

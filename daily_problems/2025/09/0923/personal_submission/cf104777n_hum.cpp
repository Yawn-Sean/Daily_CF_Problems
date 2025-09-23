#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif


template<class S>
struct Trie {
public:
  explicit Trie(S max_value, int size) {
    pt = 1;
    bit = 64 - __builtin_clzll(max_value);
    int total = size * bit + 1;
    zero.resize(total, -1);
    one.resize(total, -1);
    cnt.resize(total, 0);
  }

  void insert(S value) {
    int node = 0;
    for (int i = bit - 1; i >= 0; i--) {
      cnt[node]++;
      if (value >> i & 1) {
        if (one[node] == -1)
          one[node] = pt++;
        node = one[node];
      } else {
        if (zero[node] == -1)
          zero[node] = pt++;
        node = zero[node];
      }
    }
    cnt[node]++;
  }

  void remove(S value) {
    int node = 0;
    for (int i = bit - 1; i >= 0; i--) {
      cnt[node]--;
      node = (value >> i & 1 ? one[node] : zero[node]);
    }
    cnt[node]--;
  }

  S findMaxXor(S v) {
    int node = 0;
    S ans = 0;
    for (int i = bit - 1; i >= 0; i--) {
      ans <<= 1;
      if (v >> i & 1) {
        if (zero[node] != -1 && cnt[zero[node]])
          node = zero[node], ans++;
        else
          node = one[node];
      } else {
        if (one[node] != -1 && cnt[one[node]])
          node = one[node], ans++;
        else
          node = zero[node];
      }
    }
    return ans;
  }

private:
  int pt, bit;
  vector<int> zero, one, cnt;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<int> nums(n - 1);
  for (auto &v: nums) cin >> v;

  for (int i = 1; i < n - 1; i++)
    nums[i] ^= nums[i - 1];

  Trie<int> trie(2 * n, n);
  trie.insert(0);
  for (auto &v: nums) trie.insert(v);

  for (int i = 0; i < n; i++) {
    if (trie.findMaxXor(i) == n - 1) {
      cout << i;
      for (auto &x: nums) cout << ' ' << (i ^ x);
      break;
    }
  }
}

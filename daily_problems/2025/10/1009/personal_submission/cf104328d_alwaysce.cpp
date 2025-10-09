#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;
const int MX = 1e7;
static vector<int> lpf(MX + 1);  // least prime factor
static vector<int> cnt(MX + 1);

void sieve() {
  iota(lpf.begin(), lpf.end(), 0);
  lpf[0] = lpf[1] = -1;
  for (int i = 2; i <= MX; i++) {
    if (lpf[i] == i) {
      for (i64 j = i; j <= MX; j += i) {
        lpf[j] = i;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  sieve();

  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  /*
    本质上：问是否存在x 满足树上有一条路径 它的长度至少是n/2
    而且要求路径上所有节点的p值都能被x整除 这样的点可能是怎样的？
   */
  vector<vector<int>> path(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    path[u].push_back(v);
    path[v].push_back(u);
  }

  for (int i = 0; i < n; i++) {
    int x = p[i];
    while (x > 1) {
      int prime = lpf[x];
      cnt[prime]++;
      while (x % prime == 0) {
        x /= prime;
      }
    }
  }

  vector<int> len(n);
  int num_check = 0;
  int max_len = 0;

  auto dfs = [&](auto&& self, int u, int fa) -> void {
    int v1 = 0, v2 = 0;
    for (auto& v : path[u]) {
      if (v != fa) {
        self(self, v, u);
        if (len[v] > v1) {
          swap(v1, v2);
          v1 = len[v];
        } else if (len[v] > v2) {
          v2 = len[v];
        }
      }
    }

    if (p[u] % num_check == 0) {
      max_len = max(max_len, v1 + v2 + 1);
      len[u] = v1 + 1;
    }
  };

  for (int i = 2; i <= MX; i++) {
    if (2 * cnt[i] > n) {
      num_check = i;
      max_len = 0;
      dfs(dfs, 0, -1);
      if (max_len * 2 > n) {
        cout << "YES";
        return 0;
      }
    }
  }

  cout << "NO";
  return 0;
}

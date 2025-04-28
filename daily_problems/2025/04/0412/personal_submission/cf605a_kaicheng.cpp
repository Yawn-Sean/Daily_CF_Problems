#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef __int128 lll;

#define mod 1000000007 // 10^9 + 7
#define MOD 998244353  // 998244353

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> pos(n + 1); //将数字的值映射到位置
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    pos[a[i]] = i;
  }

  int max_len = 1, curr_len = 1;
  for (int i = 2; i <= n; i++) {
    if (pos[i] > pos[i - 1]) {      
    //检查数字 i 是否在 i-1 的后面,如果是，说明 i-1 和 i 在原数组中是顺序的
      curr_len++;
      max_len = max(max_len, curr_len);
    } else {
      curr_len = 1;
    }
  }

  int ans = n - max_len;

  cout << ans;
}

int main() {
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
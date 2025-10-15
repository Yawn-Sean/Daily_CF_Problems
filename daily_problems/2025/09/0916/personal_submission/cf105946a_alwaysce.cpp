#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MOD = 998244353;

/*
给你一个长度为n的数组 a[1],...,a[n]
每个元素的值在1到10^18之间 且约数个数不超过3

要么是质数(两个因子) 要么是质数的平方数(三个因子) 要么是1(一个因子)
*/

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  map<i64, int> mp;
  for (int i = 0; i < n; i++) {
    i64 x;
    cin >> x;
    mp[x]++;
  }

  // x+1, x+2, x+4
  i64 c1 = mp[1], c2 = mp[2], c4 = mp[4];

  // 1+1=2, 1+2=3, 2+2=4
  i64 ans = 1ll * c1 * (c1 - 1) * c2;  // 1+1=2

  // 对于x > 4的数字 只能是奇数
  for (auto& [k, v] : mp) {
    if (k <= 2) continue;
    if (k == 3) {
      ans += 2ll * v * c1 * c2;  // 1+2=3
    } else if (k == 4) {
      ans += 1ll * v * c2 * (c2 - 1);  // 2+2=4
      if (mp.find(3) != mp.end()) {
        ans += 2ll * v * c1 * mp[3];  // 1+3=4
      }
    } else if (k % 2 == 1) {
      i64 sub_1 = mp.find(k - 1) != mp.end() ? mp[k - 1] : 0;
      i64 sub_2 = mp.find(k - 2) != mp.end() ? mp[k - 2] : 0;
      ans += 2ll * v * c1 * sub_1;  // 1 + (k-1)
      ans += 2ll * v * c2 * sub_2;  // 2 + (k-2)
      if (k >= 7) {
        i64 sub_4 = mp.find(k - 4) != mp.end() ? mp[k - 4] : 0;
        ans += 2ll * v * c4 * sub_4;  // 4 + (k-4)
      }
    }
  }
  cout << ans << endl;

  return 0;
}

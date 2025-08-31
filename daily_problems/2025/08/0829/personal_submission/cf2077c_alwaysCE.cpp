#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MX = 2e5;
i64 mod = 998244353;
i64 pw2[200005];

/*
    定义函数
    F(l, r) = (r-l+1) - 2*zero(v[l:r])
    v为s的一个合法子序列
    s是一个01字符串 len(s)=n <= 2 * 10^5
    你需要对于score = max_i{F(1,i)*F(i+1,|v|)} 对所有s的合法子序列v进行求和，即寻找 sum_{v}(score), |v|为子序列长度

    在不考虑修改的情况下 怎么分析这个sum-of-max
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  pw2[0] = 1;
  for (int i = 1; i <= MX; i++) {
    pw2[i] = pw2[i - 1] * 2 % mod;
  }
  i64 rev4 = ((mod + 1) / 2 + mod) / 2;

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    // C = l - 2*x 定义为子序列长度l  子序列内0的个数为x
    // F(1,i) * F(i+1,|v|) max 化简可以得到一个只和(l-x)有关的式子
    // max = floor(C^2 / 4) 对于一个给定的序列
    // 1的个数减去0的个数=C

    /*
        第一个转化 变成求所有的 (cnt0 - cnt1)^2

        拆开 cnt0^2 / cnt1^2 平方项
        
    */
    i64 c0 = 0, c1 = 0;
    for (auto &c : s) {
      if (c == '0') {
        ++c0;
      } else {
        ++c1;
      }
    }

    while (q--) {
      int idx;
      cin >> idx;
      idx--;
      if (s[idx] == '0') {
        c0--; c1++;
        s[idx] = '1';
      } else {
        c1--; c0++;
        s[idx] = '0';
      }

      i64 ans = c0 * (c0 + 1) / 2 % mod;
      ans += c1 * (c1 + 1) / 2 % mod;
      ans -= c0 * c1 % mod;
      ans = (ans - 1 + mod) % mod;

      ans = ans * pw2[n - 1] % mod;
      ans = ans * rev4 % mod;
      cout << ans % mod << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string n;
  cin >> n;

  /*
    输入数字n
    每个数字间隔都有45%的概率插入加号，45%的概率插入减号，10%的概率不插入运算符。
    问最终表达式期望是多少
  */
  int k = (int)n.size();
  long double ans = 0.0L;
  long double p = 1.0L;
  for (int i = 0; i < k; i++) {
    int d = n[i] - '0';

    int m = k - 1 - i;
    // 前面 0.1^(i-1) * d
    // 后面 (1 + 0.9m) * d
    long double coef = p * (1.0L + 0.9L * m);
    ans = ans + coef * d;
    p = p * 0.1L;
  }

  cout << fixed << setprecision(10) << ans << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

// Hint: Change the value to the sum of absolute functions.
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<i64> p(n), q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }

  /*
  
    你需要求解这个数值
    sum_i= 1 to  N
      sum j = 1 to N
        min(|p[i] - p[j]|, |q[i] - q[j]|)

    怎么拆分/重组能够让i和j分开呢
    或者min这个式子有什么性质可以利用?

    N <= 10^6, p[i],q[i]<=10^6

    min(x,y) = x + y - max(x, y)
    max(x, y) = (|x-y| + |x+y|) / 2

    所以先拆成 |p[i]-p[j]|+|q[i]-q[j]| - (...)/ 2

    发现原来的式子等于
    r[i]=p[i]+q[i]
    s[i]=p[i]-q[i]
    sum(p[i]-p[j]) + sum(q[i]-q[j]) - 1/2 * (sum(|p[i]-p[j]-q[i]+q[j]|) + sum(|p[i]-p[j]+q[i]-q[j]|))

    = sum(p[i]-p[j]) + sum(q[i]-q[j]) - 1/2 * (sum(|(p[i]-q[i])-(p[j]-q[j])|) + sum(|(p[i]+q[i])-(p[j]+q[j])|))
    = sum(p[i]-p[j]) + sum(q[i]-q[j]) - 1/2 * (sum(|s[i]-s[j]|) + sum(|r[i]-r[j]|))

    那么对于这种类型我们直接排个序就能求了 求4次即可

    前面这个  p[i]-p[j] or p[j]-p[i] + q[i]-q[j] or q[j]-q[i] 这种绝对值的和
    
  */

  vector<i64> r(n), s(n);
  for (int i = 0; i < n; i++) {
    r[i] = p[i] + q[i];
    s[i] = p[i] - q[i];
  }

  auto calc = [&](vector<i64>& v) -> i64 {
    sort(v.begin(), v.end());
    i64 res = 0;
    i64 sum = 0;
    for (int i = 0; i < n; i++) {
      res += 1ll * v[i] * i - sum;
      sum += v[i];
    }
    return res;
  };

  i64 ans = 0;
  ans += calc(p);
  ans += calc(q);

  ans -= (calc(r) + calc(s)) / 2;
  cout << 2ll * ans << endl;
  return 0;
}

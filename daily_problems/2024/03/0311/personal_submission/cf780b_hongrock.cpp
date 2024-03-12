#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;
constexpr double eps = 1e-8;

int n, x[N], v[N];

double calc(double p){
  double ret = 0.0;
  for(int i=1; i<=n; ++i){
    ret = max(ret, fabs(x[i] - p) / v[i]);
  }
  return ret;
}

void _main(){
  cin >> n;
  for(int i=1; i<=n; ++i) cin >> x[i];
  for(int i=1; i<=n; ++i) cin >> v[i];
  double low = 0.0, top = 1e9, m1, m2, a1, a2, ans = top;
  for(int i=0; i<100; ++i){
    m1 = low + (top - low) / 3.0;
    m2 = top - (top - low) / 3.0;
    a1 = calc(m1);
    a2 = calc(m2);
    if(a1 <= a2){
      ans = min(ans, a1);
      top = m2 - eps;
    } else {
      ans = min(ans, a2);
      low = m1 + eps;
    }
  }
  cout << fixed << setprecision(10) << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

void _main(){
  int n, m;
  cin >> m >> n;
  double pre = 1.0, cur;
  double ans = 0.0;
  for(int i=m; i>=1; --i){
    cur = pow((i - 1.0) / m, n);
    ans += i * (pre - cur);
    pre = cur;
  }
  cout << fixed << setprecision(8) << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

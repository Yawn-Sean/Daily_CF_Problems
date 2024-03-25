#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 1e9 + 9;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, a, b, k;
char s[N];

ll pow_mod(ll x, ll p){
  ll s = 1;
  while(p){
    if(p & 1) s = s * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return s;
}

void _main(){
  cin >> n >> a >> b >> k >> s;
  ll ans = 0;
  int m = (n + 1) / k;
  ll x = b * pow_mod(a, mod - 2) % mod;
  ll r = pow_mod(x, k);
  ll val;
  for(int i=0; i<k; ++i){
    if(r == 1){
      val = m * pow_mod(x, i) % mod;
    } else {
      ll up = pow_mod(x, i) - pow_mod(x, i + n + 1);
      ll down = 1 - r;
      up = (up % mod + mod) % mod;
      down = (down % mod + mod) % mod;
      val = up * pow_mod(down, mod - 2) % mod;
    }
    if(s[i] == '-'){
      ans -= val;
    } else {
      ans += val;
    }
  }
  ans = (ans % mod + mod) % mod;
  ans = ans * pow_mod(a, n) % mod;
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

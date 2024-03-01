#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e5 + 1;

vector<int> fac[N];
int n, s[N];

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
  cin >> n;
  int mx = 0, x;
  for(int i=1; i<=n; ++i){
    cin >> x;
    ++s[x];
    mx = max(mx, x);
  }
  for(int i=1; i<=mx; ++i){
    for(int j=i; j<=mx; j+=i){
      fac[j].pb(i);
    }
  }
  for(int i=1; i<=mx; ++i)  s[i] += s[i-1];
  ll ans = 0;
  for(int i=1; i<=mx; ++i){
    int num = s[mx] - s[i-1];
    ll tmp = pow_mod(fac[i].size(), num) - pow_mod(fac[i].size() - 1, num);
    tmp = (tmp % mod + mod) % mod;
    int len = fac[i].size();
    for(int j=len-2; j>=0; --j){
      tmp = tmp * pow_mod(j + 1, s[fac[i][j + 1] - 1] - s[fac[i][j] - 1]) % mod;
    }
    ans += tmp;
  }
  cout << ans % mod << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

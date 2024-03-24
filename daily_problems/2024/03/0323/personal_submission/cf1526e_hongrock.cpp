#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 4e5 + 10;

int n, k, a[N], idx[N];
ll fac[N], rev[N];

ll pow_mod(ll x, ll p){
  ll s = 1;
  while(p){
    if(p & 1) s = s * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return s;
}

ll C(int n, int m){
  if(n < m) return 0;
  return fac[n] * rev[m] % mod * rev[n - m] % mod;
}

void _main(){
  cin >> n >> k;
  for(int i=0; i<n; ++i){
    cin >> a[i];
    idx[a[i]] = i;
  }
  idx[n] = -1;
  int cnt = 0;
  for(int i=0; i<n-1; ++i){
    if(idx[a[i] + 1] > idx[a[i+1]+1]){
      ++cnt;
    }
  }
  if(k <= cnt){
    cout << "0\n";
    return;
  }
  int m = k + n;
  fac[0] = 1;
  for(int i=1; i<=m; ++i){
    fac[i] = fac[i-1] * i % mod;
  }
  rev[m] = pow_mod(fac[m], mod - 2);
  for(int i=m; i>=1; --i){
    rev[i-1] = rev[i] * i % mod;
  }
  cout << C(k - 1 - cnt + n, n) << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

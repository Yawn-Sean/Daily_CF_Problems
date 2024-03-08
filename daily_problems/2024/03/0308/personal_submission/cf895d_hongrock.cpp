#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 1e9 + 7;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;
constexpr int M = 32;

int n, cnt[M], tmp[M];
string s, t;
ll fac[N], rev[N], sub[N];
ll a[M];

int lowbit(int x){
  return x & (-x);
}

void add(int x, ll v){
  if(v < 0) v += mod;
  for(; x<=26; x += lowbit(x)) a[x] = (a[x] + v) % mod;
}

ll sum(int x){
  ll ret = 0;
  for(; x>0; x-=lowbit(x))  ret += a[x];
  return ret % mod;
}

ll sum(int l, int r){
  if(l > r) return 0;
  ll ret = sum(r) - sum(l - 1);
  return (ret % mod + mod) % mod;
}

ll pow_mod(ll x, int p){
  ll s = 1;
  while(p){
    if(p & 1) s = s * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return s;
}

ll solve(string &s){
  ll ret = 0, suf = 1;
  for(int j=1; j<=26; ++j)  a[j] = 0;
  for(int j=1; j<=26; ++j){
    tmp[j] = cnt[j];
    suf = suf * rev[tmp[j]] % mod;
    add(j, sub[tmp[j]]);
  }

  int v = s[0] - 'a' + 1;
  ret = suf * sum(1, v - 1) % mod * fac[n - 1] % mod;

  for(int i=1; i<n; ++i){
    if(!tmp[v]) break;
    add(v, -sub[tmp[v]]);
    suf = suf * sub[tmp[v]--] % mod;
    add(v, sub[tmp[v]]);
    v = s[i] - 'a' + 1;
    ret += (suf * sum(1, v - 1) % mod * fac[n - i - 1] % mod);
  }
  return ret % mod;
}

void _main(){
  cin >> s >> t;
  n = s.length();
  fac[0] = 1;
  for(int i=1; i<=n; ++i) fac[i] = fac[i-1] * i % mod;
  rev[n] = pow_mod(fac[n], mod - 2);
  for(int i=n; i>=1; --i) rev[i-1] = rev[i] * i % mod;
  for(int i=1; i<=n; ++i){
    sub[i] = fac[i] * rev[i-1] % mod;
  }
  for(int i=0; i<n; ++i){
    ++cnt[s[i] - 'a' + 1];
  }
  ll ans = solve(t) - solve(s) - 1;
  ans = (ans % mod + mod) % mod;
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}
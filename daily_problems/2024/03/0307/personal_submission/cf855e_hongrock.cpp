#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int T, b;
ll l, r, dp[11][64][1<<10], lazy[11][64];

void init(){
  ll lim = (ll)1e18;
  for(int b=2; b<=10; ++b){
    dp[b][0][0] = 1;
    unsigned long long cur = 1;
    for(int i=1; cur <= lim; ++i){
      for(int j=0; j<1<<b; ++j){
        for(int k=0; k<b; ++k){
          dp[b][i][j^(1<<k)] += dp[b][i-1][j];
        }
      }
      lazy[b][i] = lazy[b][i-1];
      for(int j=1; j<b; ++j){
        lazy[b][i] += dp[b][i-1][1<<j];
      }
      cur *= b;
    }
  }
}

ll solve(ll v, int b){
  if(!v)  return 0;
  vector<int> buf;
  while(v){
    buf.pb(v % b);
    v /= b;
  }
  int len = buf.size();
  ll ret = lazy[b][len - 1];
  int st = 0;
  for(int i=len-1; i>=0; --i){
    int g = i == len - 1 ? 1 : 0;
    for(int j=g; j<buf[i]; ++j){
      int st1 = st ^ (1 << j);
      ret += dp[b][i][st1];
    }
    st ^= (1 << buf[i]);
  }
  if(st == 0) ret += 1;
  return ret;
}

void _main(){
  init();
  cin >> T;
  while(T--){
    cin >> b >> l >> r;
    cout << solve(r, b) - solve(l - 1, b) << '\n';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

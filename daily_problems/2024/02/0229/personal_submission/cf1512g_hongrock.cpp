#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e7 + 10;

int m, primes[N], ans[N];
ll f[N], g[N];
bool vis[N];

void _main(){
  f[1] = g[1] = 1;
  for(int i=2; i<N; ++i){
    if(!vis[i]){
      primes[m++] = i;
      f[i] = g[i] = i + 1;
    }
    for(int j=0; j<m && 1ll * i * primes[j] < N; ++j){
      vis[i * primes[j]] = 1;
      if(i % primes[j] == 0){
        g[i * primes[j]] = g[i] * primes[j] + 1;
        f[i * primes[j]] = f[i] / g[i] * g[i * primes[j]];
        break;
      }
      f[i * primes[j]] = f[i] * f[primes[j]];
      g[i * primes[j]] = primes[j] + 1;
    }
  }
  memset(ans, -1, sizeof(ans));
  for(int i=1; i<N; ++i){
    if(f[i] < N && ans[f[i]] == -1){
      ans[f[i]] = i;
    }
  }
  int T, n;
  cin >> T;
  while(T--){
    cin >> n;
    cout << ans[n] << '\n';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

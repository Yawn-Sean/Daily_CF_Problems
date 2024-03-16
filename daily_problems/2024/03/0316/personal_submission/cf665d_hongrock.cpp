#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e3 + 10;
constexpr int M = 2e6 + 10;

int n, a[N];
bool vis[M];
int primes[M], m;
vector<int> ans;

void init(){
  for(int i=2; i<M; ++i){
    if(!vis[i]){
      primes[m++] = i;
    }
    for(int j=0; 1ll * primes[j] * i < M; ++j){
      vis[primes[j] * i] = 1;
      if(i % primes[j] == 0){
        break;
      }
    }
  }
}

void solve(){
  int one = 0;
  for(int i=0; i<n; ++i){
    if(a[i] == 1) ++one;
  }
  if(one > 1){
    ans.resize(one, 1);
    for(int i=0; i<n; ++i){
      if(a[i] > 1 && !vis[a[i] + 1]){
        ans.pb(a[i]);
        break;
      }
    }
    return;
  }
  for(int i=0; i<n; ++i){
    for(int j=i+1; j<n; ++j){
      if(!vis[a[i] + a[j]]){
        ans.pb(a[i]);
        ans.pb(a[j]);
        return;
      }
    }
  }
  ans.pb(a[0]);
  return;
}

void _main(){
  init();
  cin >> n;
  for(int i=0; i<n; ++i){
    cin >> a[i];
  }
  solve();
  cout << ans.size() << '\n';
  for(int v : ans)  cout << v << ' ';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

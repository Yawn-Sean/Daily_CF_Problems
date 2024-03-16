#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 3e5 + 10;

int n, Q, dep[N];
ll add, sub[N], ans[N];
vector<int> V[N];
vector<pii> G[N];

void dfs(int x, int fa){
  for(auto [d, v] : G[x]){
    add += v;
    sub[min(n+1, dep[x] + d + 1)] += v;
  }
  add -= sub[dep[x]];
  ans[x] = add;
  for(int y : V[x]){
    if(y == fa) continue;
    dep[y] = dep[x] + 1;
    dfs(y, x);
  }
  add += sub[dep[x]];
  for(auto [d, v] : G[x]){
    sub[min(n+1, dep[x] + d + 1)] -= v;
    add -= v;
  }
}

void _main(){
  cin >> n;
  int x, y, z;
  for(int i=1; i<n; ++i){
    cin >> x >> y;
    V[x].pb(y); V[y].pb(x);
  }
  cin >> Q;
  while(Q--){
    cin >> x >> y >> z;
    G[x].pb(y, z);
  }
  dep[1] = 0;
  dfs(1, 0);
  for(int i=1; i<=n; ++i) cout << ans[i] << " \n"[i == n];
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

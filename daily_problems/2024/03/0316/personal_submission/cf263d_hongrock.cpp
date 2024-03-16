#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, m, k;
int vis[N];
vector<int> V[N];

void _main(){
  cin >> n >> m >> k;
  int x, y;
  while(m--){
    cin >> x >> y;
    V[x].pb(y); V[y].pb(x);
  }
  int idx = 0;
  x = 1;
  vis[1] = ++idx;
  for(;;){
    bool flag = 0;
    for(int y : V[x]){
      if(!vis[y]){
        vis[y] = ++idx;
        flag = 1;
        x = y;
        break;
      }
    }
    if(!flag)  break;
  }
  int mi = x;
  for(int y : V[x]){
    if(vis[y] < vis[mi]){
      mi = y;
    }
  }
  vector<pii> ans;
  for(int i=1; i<=n; ++i){
    if(vis[i] >= vis[mi]){
      ans.pb(vis[i], i);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << '\n';
  for(auto [x, y] : ans)  cout << y << ' ';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

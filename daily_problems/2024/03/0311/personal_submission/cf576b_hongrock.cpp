#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n, a[N];
bool vis[N];
vector<pii> ans;

bool ok(){
  for(int i=1; i<=n; ++i){
    if(a[i] == i){
      for(int j=1; j<=n; ++j){
        if(i != j)  ans.pb(j, i);
      }
      return 1;
    }
  }
  if(n & 1) return 0;
  int x = -1, y = -1;
  for(int i=1; i<=n; ++i){
    if(a[a[i]] == i){
      x = i;
      y = a[i];
      break;
    }
  }
  if(x == -1) return 0;
  ans.pb(x, y);
  vis[x] = vis[y] = 1;
  for(int i=1; i<=n; ++i){
    if(vis[i])  continue;
    int p = i;
    int len = 0;
    while(!vis[p]){
      vis[p] = 1;
      ++len;
      ans.pb(x, p);
      swap(x, y);
      p = a[p];
    }
    if(len & 1) return 0;
  }
  return 1;
}

void _main(){
  cin >> n;
  for(int i=1; i<=n; ++i){
    cin >> a[i];
  }
  if(ok()){
    cout << "YES\n";
    for(auto [x, y] : ans)  cout << x << ' ' << y << '\n';
  } else {
    cout << "NO\n";
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e5 + 10;

int n, s[N], h[N], a[N], fa[N];
vector<int> V[N];

bool dfs(int x, int d){
  if(d & 1){
    if(!V[x].size())  a[x] = 0;
    else {
      int mi = inf;
      for(int y : V[x]){
        mi = min(mi, s[y] - s[fa[x]]);
      }
      if(mi < 0)  return 0;
      a[x] = mi;
      s[x] = s[fa[x]] + a[x];
    }
  } else {
    a[x] = s[x] - s[fa[x]];
    if(a[x] < 0)  return 0;
  }
  for(int y : V[x]){
    if(!dfs(y, d ^ 1)){
      return 0;
    }
  }
  return 1;
}

void _main(){
  cin >> n;
  for(int i=2; i<=n; ++i){
    cin >> fa[i];
    V[fa[i]].pb(i);
  }
  for(int i=1; i<=n; ++i) cin >> s[i];
  if(dfs(1, 0)){
    cout << accumulate(a + 1, a + 1 + n, 0ll) << '\n';
  } else {
    cout << "-1\n";
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}
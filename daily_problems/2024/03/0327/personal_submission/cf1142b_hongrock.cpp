#include<bits/stdc++.h>
using namespace std;

constexpr int N = 2e5 + 10;

int n, m, Q, p[N], idx[N], pre[N];
int stk[N], lft[N];
vector<int> V[N];

void dfs(int x, int dep){
  stk[dep] = x;
  if(dep >= n){
    lft[x] = stk[dep - n + 1];
  }
  for(int y : V[x]){
    dfs(y, dep + 1);
  }
}

void _main(){
  cin >> n >> m >> Q;
  for(int i=1; i<=n; ++i){
    cin >> p[i];
    idx[p[i]] = i;
  }
  int x;
  for(int i=1; i<=m; ++i){
    cin >> x;
    x = idx[x];
    int y = x - 1;
    if(y == 0)  y = n;
    V[pre[y]].push_back(i);
    pre[x] = i;
  }
  dfs(0, 0);
  for(int i=2; i<=m; ++i) lft[i] = max(lft[i], lft[i-1]);
  int L, R;
  string ans = string(Q, '0');
  for(int i=0; i<Q; ++i){
    cin >> L >> R;
    if(lft[R] >= L) ans[i] = '1';
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}

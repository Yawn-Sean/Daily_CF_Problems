#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 4e5 + 10;

int n, m, Q, cnt, fa[N], sz[N];

int find_fa(int x){
  return x == fa[x] ? x : (fa[x] = find_fa(fa[x]));
}

void join(int x, int y){
  x = find_fa(x); y = find_fa(y);
  if(x == y)  return;
  --cnt;
  if(sz[x] < sz[y]) swap(x, y);
  fa[y] = x;
  sz[x] += sz[y];
}

void _main(){
  cin >> n >> m >> Q;
  iota(fa + 1, fa + 1 + n + m, 1);
  fill(sz + 1, sz + 1 + n + m, 1);
  int x, y;
  cnt = n + m;
  for(int i=1; i<=Q; ++i){
    cin >> x >> y;
    join(x, y + n);
  }
  cout << cnt - 1 << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}